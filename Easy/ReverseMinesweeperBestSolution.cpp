#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int DX[] = {0, -1, -1, -1, 0, 1, 1, 1};
int DY[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main() 
{
    int w, h;
    cin >> w; cin.ignore();
    cin >> h; cin.ignore();
    vector<string> lines;
    for (int i = 0; i < h; i++) 
    {
        string line;
        getline(cin, line);
        lines.push_back(line);
    }
    for (int y = 0; y < h; ++y) 
    {
        for (int x = 0; x < w; ++x) 
        {
            if (lines[y][x] == 'x') 
            {
                cout << ".";
            } 
            else 
            {
                int cnt = 0;
                for (int dir = 0; dir < 8; ++dir) 
                {
                    int nx = x + DX[dir];
                    int ny = y + DY[dir];
                    if (ny < 0 || nx < 0 || ny >= h || nx >= w) 
                    {
                        continue;
                    }
                    if (lines[ny][nx] == 'x') 
                    {
                        ++cnt;
                    }
                }
                if (cnt == 0) 
                {
                    cout << ".";
                } 
                else 
                {
                    cout << cnt;
                }
            }
        }
        cout << endl;
    }
}