#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size:" << endl;
    cin >> size;
    char *p = new char[size];
    for (int i = 0; i <= size; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i <= size; i++)
    {
        cout << p[i] << " ";
    }
    delete[] p;
    return 0;
}