#include <iostream>
#include <string.h>
using namespace std;
//这题是指交换一次位置后仍然能够配对成功
//2020-09-01 21:49:25	Accepted	5831	202MS	1620K	783 B	G++
int main() {
	int k, n, l, r;
	string s;
	cin>>k;
	while(k--) {
		bool flag = 0;
		cin>>n>>s;
		l = 0;
		r = 0;
		for(int i=0; i<n; i++) {
			if(s[i] == '(')
				l++;
			if(s[i] == ')')
				r++;
		}
		if(l != r) {
			cout<<"No"<<endl;
			continue;
		}
		else {
			if(l+r == 2) { //长度为2的，()或 )( 
				if(s[0] == '(')	flag = 1;
				if(s[0] == ')')	flag = 0;
			}
			else {
				int cnt = 0;
				for(int i=0; i<n; i++) {
					if(s[i] == '(')
						cnt++;
					else if(s[i] == ')')
						cnt--;
					//及时判断 
					if(cnt == -3) {
						flag = 1;
						break;
					}
				}
			}
		}
		if(flag) 
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	
	return n;
} 
