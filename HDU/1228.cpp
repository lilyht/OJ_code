#include <iostream>
#include <string>
#include <string.h>
#include <map>
using namespace std;
//2020-08-22 15:55:46	Accepted	1228	0MS	1428K	785 B	G++
map<string, int> mp;
int num[5];

void init() {
	mp["zero"] = 0;
	mp["one"] = 1;
	mp["two"] = 2;
	mp["three"] = 3;
	mp["four"] = 4;
	mp["five"] = 5;
	mp["six"] = 6;
	mp["seven"] = 7;
	mp["eight"] = 8;
	mp["nine"] = 9; 
}

int main() {
	string s, t = "";
	int idx = 0;
	int res;
	bool flag = 0;
	init();
	while(cin>>s) {		
		int x = 0;
		t = s;
		while(t != "+") {
			x = x*10 + mp[t];
			cin>>t;
			if(t == "=") {
				getchar();
				flag = 1;
				break;
			}
			
		}
		num[idx++] = x;
		if(flag == 1) {
			flag = 0;
			res = 0;
			for(int i=0; i<idx; i++) {
				res += num[i];
			}
			if(res == 0)	return 0;
			cout<<res<<endl;
			idx = 0;
			memset(num, 0, sizeof(num));
		}
	}
	return 0;
}
