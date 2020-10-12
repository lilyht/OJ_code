#include <iostream>
#include <string.h>
using namespace std;
//WA了，听说是字典树就没做了 
int main() {
	string s;
	while(cin>>s) {
		int len = s.length();
		if(len < 3)	continue;
		int l=0, r=0;
		for(int i=0; i<len-2; i++) {
			if(s[i] == 'h' && s[i+1] == 'a' && s[i+2] == 't') {
				l = i;
				r = i+2;
				
				if(l == 0 && r < len-1) {
					cout<<s<<endl;
					break;
				}
				else if(l > 0 && r == len-1) {
					cout<<s<<endl;
					break;
				}
//				cout<<"l: "<<l<<", r: "<<r<<endl;
//				break;
			}
		}
		if(l == r)	continue;
	}
	return 0;
} 
/*
hhathat
a
ahat
hat
hatword
hziee
word
*/
