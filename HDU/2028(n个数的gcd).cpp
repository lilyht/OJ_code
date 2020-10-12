#include <iostream>
using namespace std;
//2020-09-07 14:41:30	Accepted	2028	15MS	1408K	340B	G++
int a[10010];
int gcd(int x, int y) {
	if(y == 0)	return x;
	else	return gcd(y, x%y);
}

int main() {
	int n;
	while(cin>>n) {
		for(int i=0; i<n; i++)	cin>>a[i];
		int ans = 1;
		for(int i=0; i<n; i++) {
			int c = gcd(ans, a[i]);
			ans = ans / c * a[i];
		}
		cout<<ans<<endl;
	} 
	
	return 0;
}
