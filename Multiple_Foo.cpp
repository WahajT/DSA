#include <iostream>
using namespace std;

int Multi(int a, int b)
{
    if (a != 0 && b != 0)
    {
        return a + Multi(a, b - 1);
    }
    else
    {
        return 0;
    }
}
int main()
{
    int x, y, Total;
    cout << "Enter the Number which you want to multiple" << endl;
    cin >> x >> y;

    Total = Multi(x, y);
    cout << "Total is:" << Total << " ";

    return 0;
}