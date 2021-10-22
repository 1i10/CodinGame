#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();

    list<int> Temperatures;

    Temperatures.push_back(0);

    for (int i = 0; i < n; i++) 
    {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();

        Temperatures.push_back(t);
    }

    Temperatures.sort();

    auto ItZero = find(Temperatures.begin(),Temperatures.end(), 0);

    int ClosestZero = 0;

    auto PrevZero = prev(ItZero);
    auto NextZero = next(ItZero);

    if(Temperatures.size() == 1)
    {
        ClosestZero = 0;
    }
    else if(PrevZero == prev(Temperatures.begin()))//only positive
    {
        ClosestZero = *NextZero;
    }
    else if (NextZero == Temperatures.end())//only negative
    {
        ClosestZero = *PrevZero;
    }
    else
    {
        if(abs(*PrevZero) < *NextZero)
        {
            ClosestZero = *PrevZero;
        }
        else
        {
            ClosestZero = *NextZero;
        }
    }
    
    cout << ClosestZero << endl;
}