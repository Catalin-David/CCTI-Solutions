#include <iostream>

using namespace std;
int getNext(int x)
{
    int c0=0, c1=0, p, result=x;
    for(int i=0; (1<<i)<=x; i++)
    {
        if(x&(1<<i))
        {
            c1++;
        }
        else
        {
            if(c1)
            {
                break;
            }
            else
            {
                c0++;
            }
        }
    }
    if(c1+c0 == 31 || c0 + c1 == 0)
    {
        return -1;
    }

    p = c1+c0;
    result |= (1<<p);
    result &= ~((1<<p)-1);
    result |= (1<<(c1-1))-1;
    return result;
}

int getPrevious(int x)
{
    int c0=0, c1=0, p, result=x;
    for(int i=0; (1<<i) <= x; i++)
    {
        if(x&(1<<i))
        {
            if(c0)
            {
                break;
            }
            else
            {
                c1++;
            }
        }
        else
        {
            c0++;
        }
    }
    if(c1+c0 == 31 || c0 + c1 == 0)
    {
        return -1;
    }

    p = c1+c0;
    result &= ~((1<<(p+1))-1);
    int mask = (1<<(c1+1))-1;
    result |= mask << (c0-1);
    return result;
}

int main()
{
    //11001 -> 10110;
    cout<<getPrevious(25)<<'\n';
    // 101100 -> 110001;
    cout<<getNext(44)<<'\n';
    return 0;
}
