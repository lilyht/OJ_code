#include <iostream>
using namespace std;
//2020-09-19 11:16:59	Accepted	1212	15MS	1400K	246 B	G++	
int main() {
	string a;
	int b;
	while(cin>>a>>b) {
		int len = a.length();
		int num = 0;
		for(int i=0; i<len; i++) {
			num = num * 10 + a[i] - '0';
			num %= b;
		}
		cout<<num<<endl;
	}
	return 0;
} 
