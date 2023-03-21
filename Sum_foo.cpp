#include <iostream>
using namespace std;

int Total_sum(int a)
{
    if (a != 0)
    {
        return a + Total_sum(a - 1);
    }
    else
    {
        return a;
    }
}

int main()
{

    int number, Total;
    cout << "Enter the number you want to sum till" << endl;
    cin >> number;
    if (number != 0)
    {
        Total = Total_sum(number);
        cout << "Total sum till this number:" << number << " "
             << "is this:" << Total << endl;
    }
    else

    {
        cout << "Try Again" << endl;
    }

    return 0;
}