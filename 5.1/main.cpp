#include <iostream>

using namespace std;

int insertAtPosition(int n, int m, int i, int j)
{
    int mask = -1;
    for(int pos = i; pos<=j; pos++)
    {
        mask = mask & (~(1<<pos));
    }
    n = n & mask;
    n = n | (m<<i);
    return n;
}


int main()
{
    cout<<insertAtPosition(1024, 19, 2, 6);
    return 0;
}
