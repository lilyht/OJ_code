#include <iostream>
#include <string>
#include <string.h>
#include <map>
using namespace std;
//2020-08-30 14:52:55	Accepted	1251	811MS	42932K	393 B	G++
int main() {
	char s[12];
	map<string, int> mp;
	mp.clear();
	while(gets(s), s[0] != '\0') {
		string str = s;
		int len = str.length();
		for(int i=1; i<=len; i++) {
			string s1(str, 0, i);
			mp[s1]++;
		}
	}
	string str;
	while(cin>>str)
		cout<<mp[str]<<endl;
	return 0;
}
