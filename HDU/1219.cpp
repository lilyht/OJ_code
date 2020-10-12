#include <iostream>
#include <cstring>
#include <map>
using namespace std;
//2020-08-14 12:58:26	Accepted	1219	31MS	1440K	404 B	G++
string sent;
map<int, int> mp;

int main() {
	while(getline(cin, sent)) {
		int len = sent.length();
		mp.clear();
		for(int i=0; i<len; i++) {
			if(sent[i] >= 'a' && sent[i] <= 'z') {
				mp[sent[i]-'a']++;
			}
			
		}
		for(int i=0; i<26; i++) {
			cout<<(char)('a' + i)<<":"<<mp[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
} 
