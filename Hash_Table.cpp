#include <iostream>
using namespace std;
struct node
{
    int data;
};
class hashing
{
private:
    node **arr;
    int size;
    int count;

public:
    hashing(int s)
    {
        size = s;
        count = 0;
        arr = new node *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = NULL;
        }
    }
    int hashingmod(int key)
    {
        return key % size;
    }
    void inserting(int key)
    {
        if (count == size)
        {
            cout << "hash is full" << endl;
            return;
        }
        int hashindex = hashingmod(key);
        while (arr[hashindex] != NULL)
        {
            hashindex = (hashindex + 1) % size;
        }
        arr[hashindex] = new node;
        arr[hashindex]->data = key;
        count++;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != NULL)
            {
                cout << arr[i]->data << " ";
            }
        }
        cout << endl;
    }
    int searchingPrime(int num)
    {

        int flag1 = 0;
        while (1)
        {
            for (int i = 2; i < (num + 1) / 2; i++)
            {
                if (num % i == 0)
                {
                    flag1 = 1;

                    break;
                }
            }
            if (flag1 == 1)
            {
                num += 1;
                flag1 = 0;
            }
            else

                return num;
        }
    }
};
int main()
{
    hashing h(5);
    h.inserting(3);
    h.inserting(4);
    h.inserting(34);
    h.inserting(65);
    h.inserting(4);
    h.display();
    h.searchingPrime(3);
    h.display();
}
