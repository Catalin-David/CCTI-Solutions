#include <iostream>
using namespace std;

void urlify(char* str, int len){
	int numSpaces=0;
	for(int i=0; i<len; i++){
        if(str[i] == ' '){
            numSpaces++;
        }
	}

	int fp = len + numSpaces*2-1;
	for(int i=len-1; i>=0; i--){
        if(str[i] == ' '){
            str[fp] = '0';
            str[fp-1] = '2';
            str[fp-2] = '%';
            fp -= 3;
        }
        else{
            str[fp] = str[i];
            fp--;
        }
	}
}


int main()
{
    char s[] = "Mr John Smith    ";
    urlify(s, 13);
    cout<<s<<'\n';
    return 0;
}
