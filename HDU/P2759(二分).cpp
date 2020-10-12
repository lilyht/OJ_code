#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	ll l = 1;
	ll r = 1000000000;
	cin>>n;
	while(l < r) {
		ll mid = (l + r) >> 1;
		ll res = mid * log10(1.0 * mid) + 1;
		if(res < n) {
			l = mid + 1;
		}
		else
			r = mid;
	}
	//attention!!! 
	cout<<l<<endl;
	
	return 0;
}
