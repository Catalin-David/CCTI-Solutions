#include <iostream>
using namespace std;

int reverseBits(int x){
    return ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
}

int main()
{
    // 011001 -> 100110
    cout<<reverseBits(25);
    return 0;
}
