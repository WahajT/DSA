#include <iostream>
#include <string>
using namespace std;

class list
{
private:
    int *arr;     //will be used to initialize an empty list and will always point to the first position.
    int size;     //total capcity of the list
    int len;      //number of current elements in the list
    int *current; //pointer to point the current position
    int *temp;    //can be used for temporary works
public:
    //Constructor for initializing List
    //You can initialize size to any value
    list()
    {
        arr = new int[3];
        current = arr;
        for (int i = 0; i <= 3; i++)
        {
            arr[i] = -1;
            len++;
        }
    }

    //overloaded constructor
    //user will pass decided the size of the list
    list(int userSize)
    {
        size = userSize;
        arr = new int[3];
        current = arr;
        for (int i = 0; i <= 3; i++)
        {
            arr[i] = -1;
            len++;
        }
    }

    //Deep Copy Constructor
    //write code to create a new list and copy elements of the list passed in the parameter
    list(list &othrList)
    {
    }

    //Clear Or Empty the List
    void clear()
    {
        start();
        for (int i = 0; i < size; i++)
        {
            current[i] = -1;
            len--;
        }
    }

    //Insert a Value at Specific Position
    void insert(int value, int pos)
    {
        start();
        for (int i = 0; i <= pos - 1; i++)
        {
            if (i == pos - 1)
            {
                *current = value;
                len++;
            }
            else
            {
                current++;
            }
        }
    }

    //Insert the given value in the list at the next available position
    void insert(int value)
    {
        start();
        while (*(current) != -1)
        {
            current++;
        }
        *current = value;
        len++;
    }

    //Remove a value at specific position
    void remove(int pos)
    {
        start();
        for (int i = pos; i < size; i++)
        {
            current[i] = current[i + 1];
        }
        len--;
    }

    //Get value stored at a specific position
    int get(int pos)
    {
        return *current = arr[pos];
    }

    //Update Existing value at a position
    void update(int value, int pos)
    {
        start();
        for (int i = 0; i < size; i++)
        {
            if (i == pos)
            {
                current[i] = value;
                break;
            }
            else
            {
                current++;
            }
        }
    }

    //Find a value in the list
    bool find(int value)
    {
        start();
        for (int i = 0; i <= size; i++)
        {
            if (*current == value)
            {
                return true;
                break;
            }
            else
            {
                return false;
            }
        }
    }

    //Return Current Length of the list
    int length()
    {
        return len;
    }

    //Move to starting position of the list
    void start()
    {
        current = arr;
    }

    //Move to the end of the list
    void end()
    {
        start();
        for (int i = 0; i <= size;)
        {
            *current = current[i];
        }
    }

    //checks whehter the list is completely filled or not
    bool isFull()
    {
        if (len == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //checks whehter the list is completely empty or not
    bool isEmpty()
    {
        if (arr == NULL)
        {
            return true;
        }
        else
        {
            false;
        }
    }
};

int main()
{
    list l1(3);
    l1.insert(10, 3);
    l1.isFull();
    l1.start();
    l1.length();
    l1.update(3, 1);

    return 0;
}