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

    void Insertation(int data)
    {
        //Case 1: one there is no node
        if (head == NULL)
        {
            head = new node;
            head->data = data;
            head->next = NULL;
            helper = head;
            tail = head;
        }
        else

        {
            tail = new node;
            tail->data = data;
            tail->next = NULL;
            helper->next = tail;
            helper = tail;
        }
    }

    void Add_Insert(int val, int index)
    {
        //Case 1:In Between
        helper = head;
        node *temp;
        if (index != 0)
        {
            for (int i = 0; i < index - 1; i++)
            {
                helper = helper->next;
            }

            temp = new node;
            temp->data = val;
            temp->next = helper->next;
            helper->next = temp;
            helper = tail;
            temp = NULL;
        }
        //Case 2:Update value on start
        else if (index == 0)
        {
            temp = new node;
            temp->data = val;
            temp->next = head;
            head = temp;
            helper = tail;
            temp = NULL;
        }
        else
        {
            cout << "LL over flow" << endl;
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
        helper = tail;
    }

    void search(int numb)
    {
        helper = head;
        while (helper != NULL)
        {
            if (helper->data == numb)
            {
                cout << "found" << endl;
                break;
            }
            else
            {
                helper = helper->next;
            }
        }

        if (helper == NULL)
        {
            cout << "Data not found" << endl;
            helper = tail;
        }
        else
        {
        }
    }
    void Check_Emptiness()
    {
        if (head == NULL)
        {
            cout << "there is no elment in LL" << endl;
        }
    }

    void Del(int num)
    {
        // Search
        node *del;
        helper = head;
        while (helper != NULL)
        {
            if (helper->data == num)
            {

                break;
            }
            helper = helper->next;
        }

        if (helper == NULL) // Not Found
        {
            cout << "Data not found" << endl;
            helper = tail;
        }
        else // If data found
        {

            // Case1: Head
            if (helper == head)
            {
                del = head;
                head = head->next;

                helper = tail;
                delete (del);
            }

            // Case2: Tail
            else if (helper == tail)
            {
                helper = head;
                while (helper->next != tail)
                {
                    helper = helper->next;
                }
                delete (tail);
                tail = helper;
                tail->next = NULL;
            }

            //Case3: In-Between

            else
            {
                del = head;

                while (del->next != helper)
                {
                    del = del->next;
                }
                helper = del;
                del = del->next;
                helper->next = helper->next->next;
                delete (del);
            }
        }
    }
};

int main()
{
    List obj;
    obj.Check_Emptiness();
    obj.Insertation(2);
    obj.Insertation(3);
    obj.Insertation(10);
    obj.Insertation(12);
    obj.Add_Insert(22, 0);
    obj.Add_Insert(33, 3);

    obj.Display();

    obj.Del(10);
    obj.Display();

    return 0;
}
