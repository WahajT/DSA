#include <iostream>
using namespace std;

void Reverse(char *start, char *end)
{

    if (start > end)
        return;
    else
    {
        char helper = *start;
        *start = *end;
        *end = helper;
        Reverse(start + 1, end - 1);
    }
}

void Reverse_Setence(char *start, char *begin, char *end)
{

    if (*end == '\0')
    {
        Reverse(begin, end - 1);
        begin = end + 1;
        Reverse(start, end - 1);
        return;
    }

    if (*end == ' ')
    {
        Reverse(begin, end - 1);
        begin = end + 1;
    }
    Reverse_Setence(start, begin, end + 1);
}

int main()
{

    char Words[] = "Cat is running";

    Reverse_Setence(Words, Words, Words);

    cout << Words;

    return 0;
}