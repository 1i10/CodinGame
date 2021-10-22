#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    // game loop
    while (1) 
    {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        if(initialTX == lightX && initialTY <= lightY)
        {
            cout << "S" << endl;
        }
        else if(initialTX == lightX && initialTY > lightY)
        {
            cout << "N" << endl;
        }
        else if(initialTX <= lightX && initialTY == lightY)
        {
            cout << "E" << endl;
        }
        else if(initialTX > lightX && initialTY == lightY)
        {
            cout << "W" << endl;
        }
        else if(initialTX > lightX && initialTY < lightY)
        {
            initialTX -= 1;
            initialTY += 1;
            cout << "SW" << endl;
        }
        else if(initialTX < lightX && initialTY > lightY)
        {
            initialTX += 1;
            initialTY -= 1;
            cout << "NE" << endl;
        }
        else if(initialTX > lightX && initialTY > lightY)
        {
            initialTX -= 1;
            initialTY -= 1;
            cout << "NW" << endl;
        }
        else
        {
            initialTX += 1;
            initialTY += 1;
            cout << "SE" << endl;
        }
        
    }
}