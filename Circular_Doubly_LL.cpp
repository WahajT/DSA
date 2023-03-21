#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *previous;
};

class Circular_Doubly
{
private:
    node *head;
    node *helper;
    node *tail;

public:
    Circular_Doubly()
    {
        head = helper = tail = NULL;
    }

    void Inseration(int val)
    {
        if (head == NULL)
        {
            head = new node;
            head->previous = NULL;
            head->data = val;
            head->next = NULL;
            helper = head;
        }
        else
        {
            tail = new node;
            tail->data = val;
            tail->previous = helper;
            helper->next = tail;
            helper = tail;
            tail->next = head;
        }
    }

    void Deletion(int val)
    {
        helper = head;

        while (helper != tail)
        {
            if (helper->data == val)
            {
                break;
            }
            else
            {
                helper = helper->next;
            }
        }
        if (helper->data != val)
        {
            cout << "Data not Found" << endl;
        }
        else
        {
            //CASE-1 Head
            if (helper == head)
            {
                head = head->next;
                head->previous = NULL;
                tail->next = head;
                delete (helper);
                helper = tail;
            }
            //CASE-2 Tail
            else if (helper == tail)
            {
                tail = tail->previous;
                tail->next = head;
                delete (helper);
                helper = tail;
            }
            //CASE-3 In Between
            else
            {
                helper->previous->next = helper->next;
                helper->next->previous = helper->previous;
                delete (helper);
                helper = tail;
            }
        }
    }

    void Display()
    {
        helper = head;
        do
        {
            cout << helper->data << endl;
            helper = helper->next;
        } while (helper != tail->next);
    }
};

int main()
{
    Circular_Doubly obj;
    cout << "-----INSERATION-----" << endl;
    obj.Inseration(1);
    obj.Inseration(2);
    obj.Inseration(3);
    obj.Inseration(4);
    obj.Inseration(5);
    obj.Inseration(6);
    obj.Inseration(7);
    obj.Inseration(8);
    obj.Display();
    cout << "-----DELETION-----" << endl;
    obj.Deletion(10);
    obj.Deletion(1);
    obj.Deletion(5);
    obj.Deletion(8);
    obj.Display();

    return 0;
}
