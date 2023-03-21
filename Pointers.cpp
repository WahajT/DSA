#include <iostream>
using namespace std;
int main()
{
    int a, b, *ptrA, *ptrB;
    cout << "Enter the two numbers" << endl;
    cin >> a >> b;
    ptrA = &a;
    ptrB = &b;
    cout << "ptrA Value:" << *ptrA << endl;
    cout << "ptrB Value:" << *ptrB << endl;
    return 0;
}
