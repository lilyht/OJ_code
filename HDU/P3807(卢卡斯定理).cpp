#include<bits/stdc++.h>
#define N 100010
using namespace std;
typedef long long ll;
ll a[N];  //代表N的阶乘mod p后的结果 
int p;
ll pow(ll y, int z, int p) {
	y %= p;
	ll ans = 1;
	for(int i=z; i; i>>=1, y=y*y%p)  //快速幂 
		if(i&1)  //奇数 
			ans = ans*y%p;
	return ans;
}

ll C(ll n, ll m) {
	if(m>n)	return 0;
	return ((a[n]*pow(a[m], p-2, p))%p * pow(a[n-m], p-2, p)%p);  //逆元，所以是乘法 
}

ll Lucas(ll n, ll m) {
	if(!m)	return 1;
	return C(n%p, m%p) * Lucas(n/p, m/p)%p;
}

int main() {
	int T, n, m;
	cin>>T; 
	while(T--) {
		cin>>n>>m>>p; 
		a[0] = 1;
		for(int i=1; i<=p; i++)
			a[i] = (a[i-1]*i)%p;
		cout<<Lucas(n+m, n)<<endl;
	}
	return 0; 
}
