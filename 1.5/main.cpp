#include <iostream>
using namespace std;

bool oneEditAway(const string &str1, const string &str2)
{
    string s1 = str1.length() >= str2.length() ? str1 : str2;
    string s2 = str1.length() < str2.length() ? str1 : str2;
    int len1 = s1.length();
    int len2 = s2.length();

    if(abs(len1-len2)>1)
        return false;

    bool flag = false;
    for(int i=0, j=0;i<len1 && j<len2;){
        if(s1[i] != s2[j]){
            if(flag)
                return false;
            flag = true;

            if(len1 == len2)
                i++,j++;
            else
                i++;
        }
        else
            i++,j++;
    }
    return true;
}


int main()
{
    cout << oneEditAway("pale", "ple")<<'\n';
    cout << oneEditAway("ple", "pale")<<'\n';
    cout << oneEditAway("pale", "pales")<<'\n';
    cout << oneEditAway("pales", "pale")<<'\n';
    cout << oneEditAway("pale", "bale")<<'\n';
    cout << oneEditAway("paes", "pales")<<'\n';
    cout << oneEditAway("pales", "paes")<<'\n';
    cout << oneEditAway("pale", "bake")<<'\n';

    return 0;
}
