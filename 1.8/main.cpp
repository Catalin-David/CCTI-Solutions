#include <iostream>
#include <unordered_map>
using namespace std;

const int rowID = 0;
const int colID = 1;

void zeroMatrix(int **matrix, int m, int n)
{
    unordered_multimap<int, int> transformations;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j] == 0)
            {
                transformations.emplace(rowID, i);
                transformations.emplace(colID, j);
            }
        }
    }

    for(auto& trans: transformations)
    {
        if(trans.first)
        {
            for(int i=0; i<m; i++)
            {
                matrix[i][trans.second] = 0;
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                matrix[trans.second][i] = 0;
            }
        }
    }
}

void nullifyRow(int **matrix, int row, int length)
{
    for(int j=0; j<length; j++)
    {
        matrix[row][j] = 0;
    }
}

void nullifyColumn(int **matrix, int column, int length)
{
    for(int i=0; i<length; i++)
    {
        matrix[i][column] = 0;
    }
}

void zeroMatrix1(int **matrix, int m, int n)
{
    bool rowHasZero=false, colHasZero=false;

    for(int j=0; j<n; j++)
    {
        if(matrix[0][j] == 0)
        {
            rowHasZero = true;
        }
    }
    for(int i=0; i<m; i++)
    {
        if(matrix[i][0] == 0)
        {
            colHasZero = true;
        }
    }

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int j=1; j<n; j++)
    {
        if(matrix[0][j] == 0)
        {
            nullifyColumn(matrix, j, m);
        }
    }
    for(int i=1; i<m; i++)
    {
        if(matrix[i][0] == 0)
        {
            nullifyRow(matrix, i, n);
        }
    }

    if(colHasZero)
    {
        nullifyColumn(matrix, 0, m);
    }
    if(rowHasZero)
    {
        nullifyRow(matrix, 0, n);
    }
}


int main()
{
    int m, n;
    cin>>m>>n;
    int **matrix = new int*[m];
    for(int i=0; i<m; i++)
    {
        matrix[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }

    zeroMatrix1(matrix, m, n);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matrix[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
