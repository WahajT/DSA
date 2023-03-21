#include <iostream>
using namespace std;

int Factorial(int number)
{
    if (number > 1)
    {
        return number * Factorial(number - 1);
    }
    else
    {
        return number;
    }
}
int main()
{
    int num, Total;
    cout << "Enter the number that whom you want factorial of:" << endl;
    cin >> num;
    if (num != 0)
    {
        Total = Factorial(num);
        cout << "The Factorial of this number:" << num << " "
             << "is this:" << Total << endl;
    }
    else

    {
        cout << "Try Again";
    }

    return 0;
}