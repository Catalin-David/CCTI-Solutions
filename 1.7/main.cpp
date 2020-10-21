#include <iostream>
using namespace std;

void rotateMatrix(int ** matrix, int n)
{
    for(int i=0; i<n/2; i++)
    {
        for(int j=i; j<n-i-1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = temp;
        }
    }

}

//4 4
//
//x x x x  (0,1)    ->   (1,3)          ->   (3,2)         ->   (2,0)       ->   (0,1)
//x x x x   i j           j  n-1-i            n-1-i, n-1-j       n-1-j,i          i j
//x x x x
//x x x x


int main()
{
    int n;
    cin>>n;
    int **matrix = new int*[n];
    for(int i=0; i<n; i++)
    {
        matrix[i] = new int[n];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }

    rotateMatrix(matrix, n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matrix[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
