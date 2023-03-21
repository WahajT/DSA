#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // int *p = NULL, x = 5;

    // p = &x;
    // cout << &p << endl;  //address of p
    // cout << *p << endl;  // print the value of variable of which p has the address
    // cout << x << endl;   // value store in address
    // *p = 9;              //WE are storing value in address x;
    // cout << *&p << endl; //Together *& cancel each other
    // cout << &*p << endl; //Together *& cancel each other
    // cout << p << endl;   //print the address stored in p
    // cout << *p << endl;  // print the value of variable of which p has the address
    // cout << x << endl;   //updated value of x;

    //-----------------------------------------------------------------------------

    int *p = new int;
    char *n = new char[8];
    *p = 25;
    cout << *p << endl;
    strcpy(n, "datastructure");
    cout << n << endl;
    delete p;
    delete[] n;

    return 0;
}
