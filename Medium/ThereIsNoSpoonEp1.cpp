#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printNodeAndNeighbors(pair<int,int> **grid, int rows, int columns, pair<int,int>emptyCell);
int searchNeighborInDirection(pair<int,int> **grid, int size, int posRow,int posCol, pair<int,int>emptyCell, bool direction);//size by columns or rows, direction by column - 1, row - 0
void printNeighbor(pair<int,int> **grid, int size, int posRow,int posCol, bool direction);

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    //init grid
    pair<int,int> **grid = new pair<int,int> *[height];
    for(int i = 0; i < height; i++)
    {
        grid[i] = new pair<int,int>[width];
    }

    pair<int,int> empty = make_pair(-999,-999);

    for (int i = 0; i < height; i++) 
    {
        string line;
        getline(cin, line); // width characters, each either 0 or .

        for (int j = 0; j < line.size(); j++)
        {
            grid[i][j] = line[j] == '0' ? make_pair(j, i) : empty;
            //cerr << "(" << grid[i][j].first << ", " << grid[i][j].second << ") ";
        }
        //cerr << endl;
    }
    
    printNodeAndNeighbors(grid, height, width, empty);

    for (int i = 0; i < height; i++) 
    {
        delete [] grid[i];
    }
    delete [] grid;
}

void printNodeAndNeighbors(pair<int,int> **grid, int rows, int columns, pair<int,int>emptyCell)
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for(unsigned int j = 0; j < columns; j++)
        {
            if(grid[i][j] != emptyCell)
            {
                cout << grid[i][j].first << " " << grid[i][j].second << " ";

                int tempJ = j + 1;
                tempJ = searchNeighborInDirection(grid, columns, i, tempJ, emptyCell, 1);

                printNeighbor(grid, columns, i, tempJ, 1);
                
                int tempI = i + 1;
                tempI = searchNeighborInDirection(grid, rows, tempI, j, emptyCell, 0);

                printNeighbor(grid, rows, tempI, j, 0);

                j = tempJ - 1;
                
            }

        }
    }
    
}

int searchNeighborInDirection(pair<int,int> **grid, int size, int posRow, int posCol, pair<int,int>emptyCell, bool direction)
{
    if(direction)
    {
        while(posCol != size && grid[posRow][posCol] == emptyCell)
        {
            posCol++;
        }
        return posCol;
    }
    else 
    {
        while(posRow != size && grid[posRow][posCol] == emptyCell)
        {
            posRow++;
        }
        return posRow;
    }
}

void printNeighbor(pair<int,int> **grid, int size, int posRow,int posCol, bool direction)
{
    if(direction)
    {
        if(posCol == size)
        {
            cout << -1 << " " << -1 << " ";
        }
        else 
        {
            cout << grid[posRow][posCol].first << " " << grid[posRow][posCol].second << " ";
        }
    }
    else 
    {
        if(posRow == size)
        {
            cout << -1 << " " << -1 << endl;
        }
        else 
        {
            cout << grid[posRow][posCol].first << " " << grid[posRow][posCol].second << endl;
        }
    }
}
