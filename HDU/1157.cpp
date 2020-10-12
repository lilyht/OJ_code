#include <iostream>
#include <algorithm>
using namespace std;
//2020-08-21 12:57:19	Accepted	1157	31MS	1460K	217 B	G++
int a[10005];

int main() {
	int n;
	while(cin>>n) {
		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a, a+n);
		n--;
		cout<<a[n/2]<<endl;;
	}
	return 0;
} 
