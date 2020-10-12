#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[100005];
//2020-09-02 20:29:32	Accepted	5777	733MS	1752K	375 B	G++
bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int t, n, k;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=0; i<n-1; i++)	cin>>a[i];
		sort(a, a+n-1, cmp);
		ll sum = 0;
		for(int i=k-1; i<n-1; i++)
			sum += a[i];
		sum += n;
		cout<<sum<<endl;
	}
		
	return 0;
}
