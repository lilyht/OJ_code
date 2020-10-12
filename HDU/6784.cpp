#include <iostream>
using namespace std;
//2020-09-15 09:30:41	Accepted	6784	1731MS	1476K	186 B	G++	
int main() {
	int test;
	double p;
	cin>>test;
	while(test--) {
		cin>>p;
		if(p > 1.0)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
	return 0;
}
