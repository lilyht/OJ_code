#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

const int N = 1000007;
ll F[N], G[N];
ll a, b, c, d, k, T, cas;
int main() {
	cin>>T;
	while(T--) {
		cin>>a>>b>>c>>d>>k;
		if(k == 0) {
			cout<<"Case "<<++cas<<": 0"<<endl;
			continue;
		}
		b /= k;
		d /= k;
		if(b > d)	swap(b,d);
		F[1] = G[1] = 0;
		for(int i=b; i>=1; --i) {
			F[i] = (b/i) * (d/i);
			G[i] = (b/i) * (b/i);
			for(int t = 2*i; t<=b; t+=i) {
				F[i] -= F[t];
				G[i] -= G[t];
			}
		}
		cout<<"Case "<<++cas<<": "<<F[1] - G[1]/2<<endl;
	}
	return 0;
}
