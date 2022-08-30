#include <iostream>
#include <string>

using namespace std;

int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();

    int x = x0;
    int y = y0;
    int startX = 0;
    int startY = 0;
    // game loop
    while (1) 
    {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        if(bomb_dir[0] == 'U')
        {
            h = y;
            y = (startY + y) / 2;
        }
        else if(bomb_dir[0] == 'D')
        {
            startY = y;
            y = h - (h - y) / 2;
        }
        
        if(bomb_dir == "R" || bomb_dir[1] == 'R')
        {
            startX = x;
            x = w - (w - x) / 2;
        }
        else if(bomb_dir == "L" || bomb_dir[1] == 'L')
        {
            w = x;
            x = (startX + x) / 2;
        }

        // the location of the next window Batman should jump to.
        cout << x << " " << y << endl;
    }
}