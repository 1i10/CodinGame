#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
using namespace std::chrono;
using namespace std;

void InputDataAndSplitLine(vector<int>* splitLine, int length);
void distanceBetweenAreaLine(vector<int> areaLength, map<int,int>*pairsLine);
void insertOrUpdatePair(int key, map<int, int>* pairsLine);
int numberOfSquareInRectangle(map<int,int> X, map<int,int> Y);

int main()
{
    auto start = high_resolution_clock::now();

    int w;
    int h;
    int countX;
    int countY;
    cin >> w >> h >> countX >> countY; cin.ignore();

    vector<int>splitLineX(countX + 1);//size = intervals of length
    InputDataAndSplitLine(&splitLineX, w);
    vector<int>splitLineY(countY + 1);
    InputDataAndSplitLine(&splitLineY, h);

    //search distance between areas
    //and add a couple how many times this distance comes across
    map<int, int> pairsLineX;//key = distance, value = count
    distanceBetweenAreaLine(splitLineX, &pairsLineX);
    map<int, int> pairsLineY;
    distanceBetweenAreaLine(splitLineY, &pairsLineY);

    int numSquare = numberOfSquareInRectangle(pairsLineX, pairsLineY);

    cout << numSquare << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cerr << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void InputDataAndSplitLine(vector<int>* splitLine, int length)
{
    int size = (*splitLine).size();
    int prevValue = 0;

    for (int i = 0; i < size - 1; i++)
    {
        int currentValue;
        cin >> currentValue; cin.ignore();

        (*splitLine)[i] = currentValue - prevValue;
        prevValue = currentValue;
    }

    (*splitLine)[size - 1] = length - prevValue;
}

void distanceBetweenAreaLine(vector<int> areaLength, map<int, int>* pairsLine)
{
    int size = areaLength.size();

    for (unsigned int i = 0; i < size; i++)
    {
        insertOrUpdatePair(areaLength[i], *&pairsLine);

        int sumArea = areaLength[i];
        for (unsigned int j = i + 1; j < size; j++)
        {
            sumArea += areaLength[j];
            insertOrUpdatePair(sumArea, *&pairsLine);
        }
    }
}

void insertOrUpdatePair(int key, map<int, int>* pairsLine)
{
    map<int, int>::iterator pos = (*pairsLine).find(key);
    if (pos == (*pairsLine).end())
    {
        (*pairsLine).insert({ key,1 });
    }
    else
    {
        (*pairsLine)[key] = pos->second + 1;
    }
}

int numberOfSquareInRectangle(map<int,int> X, map<int,int> Y)
{
    int num = 0;

    for (const auto values1 : X)
    {
        map<int, int>::iterator pos = Y.find(values1.first);
        if (pos != Y.end())
        {
            num += values1.second * pos->second;
        }
    }

    return num;
}