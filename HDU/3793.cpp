#include <iostream>
#include <string.h>
using namespace std;
//2020-09-06 13:51:43	Accepted	3793	0MS	1400K	457 B	G++
string s;
int main() {
	while(cin>>s) {
		if(s == "#")	break;
		int len = s.length();
		bool flag = true;
		for(int i=0; i<len; i++) {
			int k = 1;
			flag = true;
			while(k <= len / 2) {
				if(s[(i+k) % len] != s[(i-k+len) % len]) {
					flag = 0;
					break;
				}
				k++;
			}
			if(flag == 1) {
				cout<<"YES "<<i<<endl;
				break;
			}
		}
		if(!flag)	cout<<"NO"<<endl;
	}
	return 0;
}
