#include <iostream>
using namespace std;
//2020-09-07 10:12:12	Accepted	2504	0MS	1396K	312B	G++ 
int gcd(int x, int y) {
	if(y == 0)	return x;
	return gcd(y, x%y);
} 

int main() {
	int a, b, c, n;
	cin>>n;
	while(n--) {
		cin>>a>>b;
		//啊！题中说了c不等于b
		for(int i=2; 1; i++) {
			if(gcd(a, i*b) == b) {
				cout<<i*b<<endl;
				break;
			}
		}
	}
	return 0;
} 
