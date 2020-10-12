#include <iostream>
using namespace std;
//2020-09-19 11:07:37	Accepted	1210	15MS	1396K	290B	G++
int main() {
	int n, m;
	while(cin>>n) {
		int pos = 2;
		m = 1;
		while(pos != 1) {
			if(pos <= n)
				pos = pos << 1;
			else {
				pos = ((pos-n) << 1) - 1;
//				cout<<"pos: "<<pos<<endl;
			}
				
			m++;
		}
		cout<<m<<endl;
	}
	return 0;
} 
