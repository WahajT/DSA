#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

class LinkedList
{
private:
    node *head, *temp, *temp2; // head will always point to first element, temp and temp2 will be used for moving and adding new nodes in the list
public:
    LinkedList()
    {

        head = NULL;
        temp = NULL;
        temp2 = NULL;
    }

    // you can take value using user input within function or by passing value to the add function using a parameter
    // assuming you will use user input within function
    void add(int value)
    {

        // code for checking whether the first element exists or not
        // if 1st element doesn't exists, write code to create 1st element
        // first element will always be pointed by head pointer
        // your code goes here
        if (head == NULL)
        {
            head = new node;
            head->value = value;
            head->next = NULL;
            temp = head;
            temp2 = head;
        }

        // if first element already exsist, move the temp pointer to the last element

        // create a new node
        // assign it a value
        // make it's next pointer null
        // the newly created node will be poined by the next pointer of last node
        // your code goes herelse
        else
        {
            temp2 = new node;
            temp2->value = value;
            temp2->next = NULL;
            temp->next = temp2;
            temp = temp2;
        }
    }

    // function to add a new value after an existing value
    // you can take value using user input within function or by passing value to the add function using a parameter
    // assuming you will use user input within function
    void addAfterSomeValue(int val)
    { // val parameter is for the value after which we want to add another value

        temp = head;
        node *insert;
        int a;
        cout << "Enter the value:" << endl;
        cin >> a;

        while (temp != NULL)
        {
            if (temp->value == val)
            {
                insert = new node;
                insert->value = a;
                insert->next = temp->next;
                temp->next = insert;
                insert = NULL;
                temp = temp2;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }

        // write code to find the value after which you want to add the new value
        // create a new node,assign it value
        // assign the address of the next pointer of the node which is pointed by temp to the next pointer of newly created node
        // assign the address of newly created node to the next pointer of node pointed by temp
        // your code goes here
    }

    void del_1st(int val)
    {
        // Search
        node *del;
        temp = head;
        while (temp != NULL)
        {
            if (temp->value == val)
            {

                break;
            }
            temp = temp->next;
        }

        if (temp == NULL) // Not Found
        {
            cout << "Data not found" << endl;
            temp = temp2;
        }
        else // If data found
        {

            // Case1: Head
            if (head->value == val)
            {
                head = head->next;
                delete (temp);
                temp = temp2;
            }

            // Case2: Tail
            else if (temp == temp2)
            {
                temp = head;
                while (temp->next != temp2)
                {
                    temp = temp->next;
                }
                delete (temp2);
                temp2 = temp;
                temp2->next = NULL;
            }

            // Case3: In-Between

            else
            {
                del = head;

                while (del->next != temp)
                {
                    del = del->next;
                }
                temp = del;
                del = del->next;
                temp->next = temp->next->next;
                delete (del);
            }
        }
    }
    void print()
    { // function to print all the values of the list
        temp = head;
        // your code goes here

        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedList obj;

    obj.add(1); // 1

    obj.add(2); // 2

    obj.add(3); // 3

    obj.add(4); // 4

    obj.add(3); // 3

    obj.print();

    cout << "After Value.." << endl;

    obj.addAfterSomeValue(3); // 3
    cout << "\n\n\n\n\n";
    obj.print();

    cout << "\nDelete" << endl;

    obj.del_1st(1);

    obj.print();

    obj.del_1st(3);

    obj.print();

    obj.del_1st(6);

    obj.print();

    return 0;
}
