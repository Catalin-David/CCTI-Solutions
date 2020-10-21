#include <iostream>
#include <set>
#include <bitset>
using namespace std;

bool uniqueCharactersDS(const string &s){
	set<char> characters;
	for(char character: s){
        if(characters.find(character) != characters.end()){
            return false;
        }
        characters.insert(character);
    }
    return true;
}

bool uniqueCharacters(const string &s){
	bool charUnique[256]={0};

	for(int character: s){
		if(charUnique[character] == true){
            return false;
        }
        charUnique[character] = true;
    }
    return true;
}

bool uniqueCharsBitset(const string &s){
    bitset<256> bits(0);
    for(int character: s){
        if(bits.test(character)){
            return false;
        }
        bits.set(character);
    }
    return true;
}

int main(){

    cout<<uniqueCharacters("dsaa")<<'\n';
    cout<<uniqueCharacters("dsa")<<'\n';
    cout<<uniqueCharactersDS("dsaa")<<'\n';
    cout<<uniqueCharactersDS("dsa")<<'\n';
    cout<<uniqueCharsBitset("dsaa")<<'\n';
    cout<<uniqueCharsBitset("dsa")<<'\n';
    return 0;
}
