#include <iostream>
#include <cstdint>
using namespace std;

void drawLine(vector<uint8_t> screen, int width, int x1, int x2, int y){
    int start_offset = x1%8;
    int first_full_byte = x1/8;
    if(start_offset){
        first_full_byte++;
    }

    int end_offset = x2%8;
    int last_full_byte = x2/8;
    if(end_offset != 7){
        last_full_byte--;
    }

    for(int b = first_full_byte; b<=last_full_byte; b++){
        screen[(width/8)*y+b] = (uint8_t)0xFF;
    }

    uint8_t startMask = (uint8_t) (0xFF >> start_offset);
    uint8_t endMask = (uint8_t) ~(0xFF >> (end_offset+1));

    if((x1/8) == (x2/8)){
        uint8_t mask = (uint8_t) (startMask & endMask);
        screen[(width/8)*y+(x1/8)] |= mask;
    }
    else{
        if(start_offset){
            int byteIndex = (width/8)*y + first_full_byte - 1;
            screen[byteIndex] |= startMask;
        }
        if(end_offset != 7){
            int byteIndex = (width/8)*y + last_full_byte + 1;
            screen[byteIndex] |= endMask;
        }
    }
}

int main()
{


    cout << "Hello world!" << endl;
    return 0;
}
