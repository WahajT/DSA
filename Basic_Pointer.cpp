#include <iostream>
using namespace std;
int main()
{
    int *p = new int;
    cout << "Enter the Value" << endl;
    cin >> *p;
    cout << "Value:" << *p << endl;
    delete p;
    return 0;
}
