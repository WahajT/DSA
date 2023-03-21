#include <iostream>
using namespace std;

struct node
{

    node *previous;
    int data;
    node *next;
};

class Doubly_Link
{
private:
    node *head;
    node *tail;
    node *helper;

public:
    Doubly_Link()
    {
        head = helper = tail = NULL;
    }
    void insert(int val)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = val;
            head->previous = NULL;
            head->next = NULL;
            helper = head;
        }
        else
        {
            tail = new node;
            tail->data = val;
            helper->next = tail;
            tail->previous = helper;
            tail->next = NULL;
            helper = tail;
        }
    }

    void Reverse()
    {
        node *temp;
        helper = temp = head;
        temp = helper->next;
        helper->next = NULL;
        helper->previous = temp;
        while (temp != NULL)
        {
            temp->previous = temp->next;
            temp->next = helper;
            helper = temp;
            temp = temp->previous;
        }
        tail = head;
        head = helper;
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
    Doubly_Link obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.Display();
    cout << "Reverse nodes" << endl;
    obj.Reverse();
    obj.Display();

    return 0;
}