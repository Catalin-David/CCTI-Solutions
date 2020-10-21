#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool areStringsPermutations(const string &s, const string &p){
    if(s.size() != p.size()){
        return false;
    }

	vector<int> app(256);

	for(int ch: s){
		app[ch]++;
    }

    for(int ch: p){
        app[ch]--;
        if(app[ch] < 0){
            return false;
        }
    }
    return true;
}

int main(){
    cout<<areStringsPermutations("sd", "safa")<<'\n';
    cout<<areStringsPermutations("sda", "sad")<<'\n';
    cout<<areStringsPermutations("aaa", "aaf")<<'\n';
    cout<<areStringsPermutations("rock baby", "rb ockaby")<<'\n';
	return 0;
}
