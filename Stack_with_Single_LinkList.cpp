#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class Stack_Link_list
{
private:
    node *head;
    node *helper;
    node *tail;

public:
    Stack_Link_list()
    {
        head = helper = tail = NULL;
    }
    void push(int val)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = val;
            head->next = NULL;
            helper = head;
        }
        else
        {
            tail = new node;
            tail->data = val;
            tail->next = NULL;
            helper->next = tail;
            helper = tail;
        }
    }

    int pop()
    {
        node *out;
        helper = head;
        while (helper != NULL)
        {
            if (helper->next == tail)
            {
                out = tail;
                tail = helper;
                tail->next = NULL;
                helper = head;
                return out->data;
            }

            else if (head == tail)
            {
                out = tail;
                helper = NULL;
                head = NULL;
                tail = NULL;
                return out->data;
            }
            else if (head == NULL)
            {
                cout << "Stack underflow" << endl;
                return 0; //Means there is no element in stack
            }
            else
            {
                helper = helper->next;
            }
        }
    }
    void Display()
    {
        helper = head;
        while (helper != NULL)
        {
            cout << helper->data << " ";
            helper = helper->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack_Link_list obj;
    cout << "-----PUSH FUNCTION-----" << endl;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.push(6);
    obj.Display();
    cout << "-----POP FUNCTION-----" << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;

    return 0;
}