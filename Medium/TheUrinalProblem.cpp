#include <iostream>
#include <string>

using namespace std;

int main()
{
    int size;
    cin >> size; cin.ignore();
    string toulets;
    getline(cin, toulets);

    int minIdx = 0;
    int counterDistance = 0;

    //first occupied
    int occupiedIdx = 0;
    while (occupiedIdx < size && toulets[occupiedIdx] != '!')
    {
        occupiedIdx++;
    }

    int maxDistance = occupiedIdx;

    //middle occupied toulets
    for (int i = occupiedIdx + 1; i < size; i++)
    {
        if (toulets[i] == '!')
        {
            if (toulets[i - 1] != '!')
            {
                int midDistance = counterDistance / 2 + 1;
                if (maxDistance < midDistance)
                {
                    maxDistance = midDistance;
                    minIdx = i - midDistance;
                }
            }
            counterDistance = 0;
        }
        else
        {
            counterDistance++;
        }
    }

    if (maxDistance < counterDistance)
    {
        minIdx = size - 1;
    }

    cout << minIdx << endl;
}