#include <iostream>
using namespace std;

class Stack
{
private:
    int *array;
    int top;
    int size;
    int *next;

public:
    Stack(int a)
    {
        size = a;
        top = -1;
        array = new int[size];
        next = array;
    }

    void push(int a)
    {
        if (top != (size - 1))
        {
            top++;
            array[top] = a;
            cout << array[top] << endl;
            *next = array[top];
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }
    int pop()
    {

        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else

        {

            *next = array[top];
            top--;

            return *next;
        }
    }
};

int main()
{
    Stack obj(5);
    cout << "-----PUSH FUNCTION----" << endl;
    obj.push(2);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.push(6);

    cout << "-----POP FUNCTION-----" << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;

    return 0;
}