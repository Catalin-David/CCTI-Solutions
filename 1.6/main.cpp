#include <iostream>
using namespace std;

void appendWithFrequency(string &str, char cc, int freq)
{
    str += cc;
    str += char(freq+int('0'));
}

string compressFrequency1(const string &str)
{
    string result;

    char cc = str[0];
    int freq = 1;

    for(int i=1; i<str.length(); i++)
    {
        if(str[i] != cc)
        {
            appendWithFrequency(result, cc, freq);
            cc = str[i];
            freq = 1;
        }
        else
        {
            freq++;
        }
    }
    appendWithFrequency(result, cc, freq);
    return result;
}

int countCompLen(const string &str)
{
    int result = 1;
    for(int i=1; i<str.length(); i++)
    {
        if(str[i] != str[i-1])
        {
            result ++;
        }
    }
    return result*2;
}

string compressFrequency2(const string &str)
{
    int compLen = countCompLen(str);
    if(compLen >= str.length())
    {
        return str;
    }

    char *s = new char[compLen];
    int finalSP=0;
    char cc = str[0];
    int counter = 1;
    for(int i=1; i<str.length(); i++)
    {
        if(str[i] != cc)
        {
            s[finalSP] = cc;
            s[finalSP+1] = char(counter+int('0'));
            finalSP += 2;
            cc = str[i];
            counter = 1;
        }
        else{
            counter++;
        }
    }
    s[finalSP] = cc;
    s[finalSP+1] = char(counter+int('0'));

    string result = string{s, compLen};
    delete s;
    return result;
}


string compress(const string &str)
{
    string freqStr = compressFrequency2(str);
    if(freqStr.length() < str.length())
    {
        return freqStr;
    }
    else
    {
        return str;
    }
}


int main()
{
    string s = "aabcccccaaa";
    cout<<compress(s)<<'\n';
    s = "a";
    cout<<compress(s)<<'\n';
    s = "abcccccaaa";
    cout<<compress(s)<<'\n';
    return 0;
}
