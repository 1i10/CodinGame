#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int SearchDifference(list<int>Arr);

int main()
{
    int N;
    cin >> N; cin.ignore();

    list<int>PowerHorses;

    for (int i = 0; i < N; i++)
    {
        int Pi;
        cin >> Pi; cin.ignore();

        PowerHorses.push_back(Pi);
    }

    PowerHorses.sort();

    cout << SearchDifference(PowerHorses) << endl;
}

int SearchDifference(list<int>Arr)
{
    list<int>::iterator It = Arr.begin();
    int CurrentDifference = 0;
    int MinDifference = 0;

    if(Arr.size() > 1)
    {
        CurrentDifference = *next(It) - *It;
        MinDifference = CurrentDifference;

        advance(It, 1);
        for (;It != Arr.end();++It)
        {
            CurrentDifference = *It - *prev(It);
            if (CurrentDifference < MinDifference)
            {
                MinDifference = CurrentDifference;
            }
        }
    }
    
    return MinDifference;
}