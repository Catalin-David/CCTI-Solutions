#include <iostream>

using namespace std;
int bitsConversion(int a, int b)
{
    int result = 0;
    while(a > 0 && b > 0)
    {
        if(a%2 != b%2)
        {
            result++;
        }
        a >>= 1;
        b >>= 1;
    }
    while(a>0)
    {
        result++;
        a >>= 1;
    }
    while(b>0)
    {
        result++;
        b >>= 1;
    }
    return result;
}

int bitsConversion2(int a, int b){
    int result = 0;
    for(int c = a^b; c != 0; c = c&(c-1)){
        result++;
    }
    return result;
}

int main()
{
    cout<<bitsConversion2(29, 15);
    return 0;
}
