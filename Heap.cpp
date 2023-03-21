#include <iostream>
#include <math.h>
using namespace std;

class heap
{
private:
    int maxsize;
    int *p;
    int n;

public:
    heap(int ms)
    {

        maxsize = ms;
        p = new int[maxsize + 1];
        n = 0;
    }

    heap(int *arr, int ms, int sz)
    {

        p = arr;
        maxsize = ms;
        n = sz;
    }

    void insert(int x)
    {
        if (n == maxsize)
        {
            cout << "The list is full: " << endl;
            return;
        }
        n++;
        int i;
        for (i = n; i > 1; i = i / 2)
        {
            if (x >= p[i / 2])
                break;

            p[i] = p[i / 2];
        }
        p[i] = x;
    }

    void heapify(int i)
    {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * +1;
        if (left <= n && p[left] < p[smallest])
            smallest = left;
        if (right <= n && p[right] < p[smallest])
            smallest = right;
        if (smallest != i)
            swap(p[i], p[smallest]);
        heapify(smallest);
    }

    void buildheap()
    {

        int startidx = n / 2;
        for (int i = startidx; i > 0; i--)
            heapify(i);
    }

    int deletemin()
    {

        int root = p[1];
        p[1] = p[n];
        n--;
        heapify(1);
        return root;
    }
    void print()
    {
        if (n == 0)
        {
            cout << "heap is empty:	" << endl;
            return;
        }
        else
        {
            for (int i = 1; i < p[maxsize]; n++)
            {
                cout << p[n];
            }
        }
    }
};

int main()
{
    heap p(13);
    p.insert(21);
    p.insert(16);
    p.insert(24);
    p.insert(31);
    p.insert(19);
    p.insert(68);
    p.insert(65);
    p.insert(26);
    p.insert(32);
    p.print();
    p.deletemin();
    p.print();
}