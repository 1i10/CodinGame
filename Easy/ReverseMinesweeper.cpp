#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char changeValue(char **values, int row, int column, int height, int width);

int main()
{
    int w;
    cin >> w; cin.ignore();
    int h;
    cin >> h; cin.ignore();

    //2d array with char values (fill '0')
    char** values = new char* [h];
    for (int i = 0; i < h; i++) 
    {
        values[i] = new char[w];
        for (int j = 0; j < w; j++) 
        {
            values[i][j] = '0';
        }
    }

    for (int i = 0; i < h; i++) 
    {
        string line;
        getline(cin, line);

        for (int j = 0; j < w; j++) 
        {
            if (line[j] == 'x')
            {
                values[i][j] = 'x';
                //if j - 1 >= 0 , i - 1 >= 0 , j + 1 < w , i + 1 < h
                try
                {
                    values[i][j - 1] = changeValue(values, i, j - 1, h, w);
                }
                catch(...){}
                try
                {
                    values[i][j + 1] = changeValue(values, i, j + 1, h, w);
                }
                catch (...) {}
                try
                {
                    values[i - 1][j] = changeValue(values, i - 1, j, h, w);
                }
                catch (...) {}
                try
                {
                    values[i + 1][j] = changeValue(values, i + 1, j, h, w);
                }
                catch (...) {}
                try
                {
                    values[i - 1][j - 1] = changeValue(values, i - 1, j - 1, h, w);
                }
                catch (...) {}
                try
                {
                    values[i - 1][j + 1] = changeValue(values, i - 1, j + 1, h, w);
                }
                catch (...) {}
                try
                {
                    values[i + 1][j - 1] = changeValue(values, i + 1, j - 1, h, w);
                }
                catch (...) {}
                try
                {
                    values[i + 1][j + 1] = changeValue(values, i + 1, j + 1, h, w);
                }
                catch (...) {}

            }
            if (values[i][j] == '0')
            {
                values[i][j] = line[j];
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (values[i][j] == 'x')
            {
                cout << '.';
            }
            else
            {
                cout << values[i][j];
            }
        }
        cout << endl;
        
        delete values[i];
    }
    delete[] values;
}

char changeValue(char** values, int row, int column, int height, int width)
{
    if (row < 0 || row == height || column < 0 || column == width)
    {
        throw (-1);
    }

    if (values[row][column] == '0' || values[row][column] == '.')
    {
        return '1';
    }
    else if(values[row][column] != 'x')
    {
        return values[row][column] + 1;
    }
}