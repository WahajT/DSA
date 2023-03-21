#include <iostream>
using namespace std;

class ADT_Array
{
private:
    int *arr;
    int *current;
    int size;
    int max_size;
    int positions = 0;

public:
    ADT_Array(int a)
    {
        max_size = a;
        arr = new int[max_size];
        current = arr;
        cout << "Enter the values" << endl;
        for (int i = 0; i <= max_size; i++)
        {
            cin >> arr[i];
        }
        size = max_size;
    }
    void insert(int val, int pos)
    {
        if (max_size - size == 0)
        {
            cout << "The arry is full" << endl;
        }
        else
        {

            for (int i = 0; i <= pos; i++)
            {
                arr[i] = arr[val];
            }

            positions++;
        }
    }

    void Remove()
    {
        current--;
        positions--;
        *current;
    }
    void Add(int data)
    {
        for (int i = 0; i < positions; i++)
        {
            arr[i] = arr[data + *current];
        }
    }

    void Get()
    {
        cout << *current << endl;
    }
    void Next()
    {
        current++;
    }
    void Back()
    {
        current--;
    }
    void Start()
    {
        current = arr;
    }
    void End()
    {
        for (int i = 0; i <= max_size; i++)
        {
            Next();
        }
    }
    void Length()
    {
        size;
    }
};
int main()
{
    ADT_Array obj(3);
    obj.Get();
    obj.insert(1, 3);
    obj.Add(5);
    obj.Back();
    obj.End();
    obj.Length();
    obj.Next();
    obj.Remove();
    obj.Start();

    return 0;
}