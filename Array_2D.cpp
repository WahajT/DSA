#include <iostream>
using namespace std;
int main()
{
    int row, col;
    cout << "Enter the size of 2D-arry" << endl;
    cout << "Enter the row:" << endl;
    cin >> row;
    cout << "Enter the col:" << endl;
    cin >> col;
    int **arry = new int *[row];
    for (int i = 0; i <= row; i++)
    {
        arry[i] = new int[col];
    }
    cout << "Enter the values:" << endl;
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            cin >> arry[row][col];
        }
    }
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            cout << arry[row][col] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i <= col; i++)
    {
        delete[] arry[col];
    }
    delete[] arry;
    return 0;
}