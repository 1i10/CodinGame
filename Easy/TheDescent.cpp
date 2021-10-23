#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> highs;
    // game loop
    while (1) 
    {
        for (int i = 0; i < 8; i++) 
        {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH; cin.ignore();
            highs.push_back(mountainH);
        }

        vector<int>::iterator maxHigh = max_element(highs.begin(),highs.end());

        cout << distance(highs.begin(), maxHigh) << endl; // The index of the mountain to fire on.

        highs.clear();
    }
}