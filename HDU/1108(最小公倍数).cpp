#include <iostream>
#include <cstdio>
using namespace std;
//2020-08-21 12:48:59	Accepted	1108	0MS	1396K	253 B	G++
int gcd(int x, int y) {
	if(y == 0)
		return x;
	else
		return gcd(y, x%y);
}

int main() {
	int a, b;
	while(cin>>a>>b) {
		int ab_gcd = gcd(a, b);
		cout<<a*b/ab_gcd<<endl;
	}
	
	return 0;
} 
