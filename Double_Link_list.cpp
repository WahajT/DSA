#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *previous;
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

    void Insert(int data)
    {
        if (head == NULL)
        {
            head = new node;
            head->next = NULL;
            head->previous = NULL;
            head->data = data;
            helper = head;
            tail = head;
        }
        else
        {
            tail = new node;
            tail->data = data;
            tail->next = NULL;
            tail->previous = helper;
            helper->next = tail;
            helper = tail;
        }
    }

    void Add_Insert(int val, int index)
    {
        node *insert;
        helper = head;
        //CASE-1 In BETWEEN
        if (index != 0)
        {

            for (int i = 0; i < index - 1; i++)
            {
                helper = helper->next;
            }
            insert = new node;
            insert->data = val;
            insert->next = helper->next;
            insert->previous = helper;
            helper->next->previous = insert;
            helper->next = insert;
            insert = NULL;
        }
        //CASE-2 On head
        else if (index == 0)
        {
            insert = new node;
            insert->data = val;
            insert->next = head;
            head->previous = insert;
            head = insert;

            insert = NULL;
        }
        else
        {
            cout << "out of bound" << endl;
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

    void search(int val)
    {
        helper = head;
        while (helper->next != NULL)
        {
            if (helper->data == val)
            {
                cout << "Found" << endl;
                break;
            }
            else
            {
                helper = helper->next;
            }
        }
        if (helper == NULL)
        {
            cout << "Not Found" << endl;
        }
    }
    void Check_Emptiness()
    {
        if (head == NULL)
        {
            cout << "DLL is empty";
        }
    }

    void Del(int val)
    {
        helper = head;

        while (helper != NULL)
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
        if (helper == NULL)
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
                delete (helper);
            }
            //CASE-2 Tail
            else if (helper == tail)
            {
                tail = tail->previous;
                tail->next = NULL;
                delete (helper);
            }
            //CASE-3 In Between
            else
            {
                helper->previous->next = helper->next;
                helper->next->previous = helper->previous;
                delete (helper);
            }
        }
    }
};

int main()
{
    List obj;
    obj.Insert(3);

    obj.Insert(2);

    obj.Insert(1);
    obj.Insert(5);
    obj.Add_Insert(33, 0);
    obj.Add_Insert(22, 3);

    obj.Display();
    obj.Del(33);
    obj.Del(2);
    obj.Del(5);

    obj.Display();

    return 0;
}
