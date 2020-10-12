#include <iostream>
using namespace std;
const int MAXN = 42;
//2020-09-07 13:43:03	Accepted	2047	0MS	1396K	225 B	G++
long long a[MAXN] = {0, 3, 8};
int main() {
	int n;
	for(int i=3; i<=40; i++)
		a[i] = 2*a[i-1] + 2*a[i-2];
	while(cin>>n) {
		cout<<a[n]<<endl;
	} 
	return 0;
} 

