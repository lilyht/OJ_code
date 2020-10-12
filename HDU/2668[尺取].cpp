#include <bits/stdc++.h>
#define LL long long
using namespace std;
//https://blog.nowcoder.net/n/17a90409cf6c4407b14a6281bfb8b7a2 
//2020-09-12 22:50:52	Accepted	6231	93MS	1760K	845 B	G++
//其实还不是很会，但是已经看了一个半小时了... 算了 
int a[100005];

//check部分是尺取法 
LL check(LL x, LL k, LL n) {
	LL ans=0, num=0;  //num: [L, R]区间内>=x的元素个数
	for(LL L=1, R=1; R<=n; R++) {
		if(num<k) {
			if(a[R] >= x) {
				num++;
			}
		}
		while(num >= k && L <= R) {
			ans += n-R+1;
			if(a[L] >= x) {
				num--;
			}
			L++;
		}
	}
	return ans;
}

int main() {
	int t;
	LL n, k, m;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld%lld%lld", &n, &k, &m);
		for(int i=1; i<=n ; i++) {
			scanf("%d", &a[i]);
		}
		LL L=1, R=1e9+7, key=0;
		while(L <= R) {
			LL mid = (L+R)/2;
			if(check(mid, k, n) >= m) {
				key = mid;
				L = mid+1;
			}
			else {
				R = mid-1;
			}
		}
		printf("%lld\n", key);
	}
	return 0;
}

