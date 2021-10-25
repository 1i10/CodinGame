#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std::chrono;
using namespace std;

vector<int>InputDataAndSplitLine(int size, int length);
void distanceBetweenAreaLine(vector<int>* areaLength);
int numberOfSquareInRectangle(vector<int> X, vector<int> Y);

int main()
{
    auto start = high_resolution_clock::now();

    int w;
    int h;
    int countX;
    int countY;
    cin >> w >> h >> countX >> countY; cin.ignore();

    vector<int>splitLineX = InputDataAndSplitLine(countX, w);
    vector<int>splitLineY = InputDataAndSplitLine(countY, h);

    //search distance between areas
    distanceBetweenAreaLine(&splitLineX);
    distanceBetweenAreaLine(&splitLineY);

    int numSquare = numberOfSquareInRectangle(splitLineX, splitLineY);

    cout << numSquare << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cerr << "Time taken by function: "
        << duration.count() << " microseconds" << endl;
}

vector<int>InputDataAndSplitLine(int size, int length)
{
    vector<int>splitLine;

    int prevValue = 0;

    for (int i = 0; i < size; i++)
    {
        int currentValue;
        cin >> currentValue; cin.ignore();

        splitLine.push_back(currentValue - prevValue);
        prevValue = currentValue;
    }

    splitLine.push_back(length - prevValue);

    return splitLine;
}

void distanceBetweenAreaLine(vector<int>* areaLength)
{
    int size = (*areaLength).size();

    for (unsigned int i = 0; i < size; i++)
    {
        int sumArea = (*areaLength)[i];
        for (unsigned int j = i+1; j < size; j++)
        {
            sumArea += (*areaLength)[j];
            (*areaLength).push_back(sumArea);
        }
    }
}

int numberOfSquareInRectangle(vector<int> X, vector<int> Y)
{
    int num = 0;

    for (auto value1 : X)
    {
        num += count_if(Y.begin(), Y.end(), [value1](int value2) {return value2 == value1; });
    }

    return num;
}