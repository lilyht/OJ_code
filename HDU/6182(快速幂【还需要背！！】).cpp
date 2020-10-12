#include <iostream>
#include <cmath> 
using namespace std;
//2020-08-21 22:46:48	Accepted	6182	0MS	1404K	540 B	G++
typedef long long ll;
ll a[16];
//预处理出来
void init() {
	for(int i=1; i<=15; i++) {
		a[i] = 1;
		ll ans = 1;
		//注意：这段还是要背一下！！！ 
		ll k = i;
		ll mi = i;
		while(mi != 0) {
			if(mi&1) {  //奇数 
				ans = ans * k;
			}
			mi = mi >> 1;
			k = k * k;
		}
		a[i] = ans;
	}
}
 
int main() {
	ll n;
//	cout<<pow(16, 16)<<endl;
	while(cin>>n) {
		int num = 0;
		init();
		int res = 0;
		for(int i=1; i<16; i++) {
//			cout<<a[i]<<" ";
			if(a[i] <= n)
				res++;
		}
		cout<<res<<endl;
	}
	return 0;
}
