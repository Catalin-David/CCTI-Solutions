#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int getCharIndex(char ch){
	if('A'<= ch && ch <= 'Z'){
        return int(ch) - int('A');
    }
    else if('a' <= ch && ch<='z'){
        return int(ch) - int('a');
    }
    else{
        return -1;
    }
}

void toggleBit(int &bitvector, int index){
	int power = (1<<index);
	if(bitvector&power){
		bitvector &= ~power;
    }
    else{
        bitvector |= power;
    }
}

bool checkPowerOfTwo(int number){
	return ((number-1)&number) == 0;
}

bool isPalindromePermutation(const string &str){
    int bitvector = 0;

    for(char ch: str){
        int index = getCharIndex(ch);
        if(index != -1){
            toggleBit(bitvector, index);
        }
    }

    return bitvector == 0 || checkPowerOfTwo(bitvector);
}



int main()
{
    string s = "Atoc taC";
    cout<<isPalindromePermutation(s)<<'\n';
    string p = "ttaco cat";
    cout<<isPalindromePermutation(p)<<'\n';
    return 0;
}
