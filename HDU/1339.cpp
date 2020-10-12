#include <iostream>
#include <cmath>
using namespace std;
//2020-09-21 16:54:13	Accepted	1339	0MS	1400K	246 B	G++
int main() {
	int t, n, q;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int p=0; p<=log(n)+1; p++) {
			q = 1<<p;
			if(n % q == 0 && ((n/q)&1))
				cout<<n/q<<" "<<p<<endl;
		}
	}
	return 0;
}
