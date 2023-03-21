#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

class List
{
private:
    node *head;
    node *helper;
    node *tail;

public:
    List()
    {
        head = tail = helper = NULL;
    }

    void insert(int data)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = data;
            head->next = NULL;
            helper = tail = head;
        }
        else
        {
            tail = new node;
            tail->data = data;
            helper->next = tail;
            helper = tail;
            tail->next = head;
        }
    }
    void ADD_Insert(int val, int pos)
    {
        node *add;
        helper = head;
        for (int i = 0; i < pos - 1; i++)
        {

            helper = helper->next;
        }
        if (helper == NULL)
        {
            cout << "position not found" << endl;
        }
        else
        {
            //CASE-1 Head
            if (helper == head)
            {
                add = new node;
                add->data = val;
                add->next = head;
                head = add;
                tail->next = head;
                add = NULL;
            }
            // CASE-2 Tail
            if (helper == tail)
            {
                add = new node;
                add->data = val;
                add->next = head;
                tail->next = add;
                tail = add;
                add = NULL;
            }
            //CASE-3 IN Between
            else
            {
                add = new node;
                add->data = val;
                add->next = helper->next;
                helper->next = add;
                add = NULL;
            }
        }
    }

    void Display()
    {
        helper = head;
        do
        {
            cout << helper->data << " ";
            helper = helper->next;
        } while (helper != tail->next);
        cout << endl;
    }
};

int main()
{
    List obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.Display();
    obj.ADD_Insert(11, 0);
    // obj.ADD_Insert(22, 1);
    // obj.ADD_Insert(55, 6);
    obj.Display();

    return 0;
}
