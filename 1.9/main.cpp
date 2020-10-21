#include <iostream>
using namespace std;


bool isSubstring(const string &str1, const string &str2){
    return str2.find(str1) != string::npos;
}

bool stringRotation(const string &str1, const string &str2){
    size_t len = str1.length();

    if(len>0 && len == str2.size()){
        string duplicated = str2 + str2;
        return isSubstring(str1, duplicated);
    }
    else
        return false;

}


int main()
{
    cout<<stringRotation("water", "terwa")<<'\n';
    cout<<stringRotation("water", "terws")<<'\n';
    cout<<stringRotation("water", "terw")<<'\n';
    return 0;
}
