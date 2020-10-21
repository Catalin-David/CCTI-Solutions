#include <iostream>
#include <limits>
using namespace std;

int flipBitWin(unsigned int x)
{
    int previous = 0, current = 0, result = 1;

    while(x!=0)
    {
        if(x%2){
            current++;
        }
        else{
            previous = current;
            current = 0;
        }
        x >>= 1;
        result = max(previous+current+1, result);
    }
    return min(result, numeric_limits<unsigned int>::digits);
}


int main()
{
    cout<<flipBitWin(1775)<<'\n';
    cout<<flipBitWin(3535)<<'\n';
    cout<<flipBitWin(~0)<<'\n';
    return 0;
}
