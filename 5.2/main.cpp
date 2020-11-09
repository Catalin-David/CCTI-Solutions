#include <iostream>
#include <sstream>
using namespace std;

string binaryToString(double binary){
    stringstream str;
    if(binary <= 0 || binary >= 1){
        return "ERROR";
    }
    str << "0.";

    while(binary != 0){
        if(str.tellp() > 32){
            return "ERROR LENGTH";
        }
        binary *= 2;
        if(binary >= 1){
            str<<'1';
            binary -= 1;
        }
        else
            str<<'0';
    }
    return str.str();
}

int main()
{
    cout<<binaryToString(0.875);
    return 0;
}
