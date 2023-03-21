#include <iostream>

using namespace std;

class Queue
{
private:
    int *array;
    int *front;
    int *rear;
    int size;
    int length;

public:
    Queue(int a)
    {
        size = a;
        array = new int[size];
        front = array;
        rear = array;
        length = 0;
    }

    bool isFull()
    {
        if (length == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (length == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }
        int *tail;
        tail = &size - 1;
        if (rear == tail)
            rear = 0;
        else
            rear++;

        *rear = val;
        cout << "enqueue val : " << *rear << endl;
        length++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflows!" << endl;
            return -1;
        }

        int *val = front;
        length--;
        int *si = &size - 1;
        if (front == si)
            front = 0;
        else
            front++;
        cout << "dequeue val : " << *val << endl;
        return *val;
    }
};

int main()
{
    Queue q(3);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    q.enqueue(1);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}