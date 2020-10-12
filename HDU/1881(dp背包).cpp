#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 35;
//01背包 
//感到，我居然自己做出来了！！！
//加油加油 
//2020-08-25 21:16:14	Accepted	1881	31MS	1428K	874 B	G++
int dp[1005];

struct node{
	int h, l, t;
}a[MAXN];

bool cmp(node x, node y) {
//	if(x.t != y.t)	
	return x.t < y.t;
}

int main() {
	int n;
	while(cin>>n && n>=0) {
		memset(dp, 0, sizeof(dp));
		int maxt = 0;
		int ans = 0;
		for(int i=0; i<n; i++) {
			cin>>a[i].h>>a[i].l>>a[i].t;
			maxt = max(maxt, a[i].t);
		}
		sort(a, a+n, cmp);
//		cout<<"=====\n";
//		for(int i=0; i<n; i++) 
//			cout<<a[i].h<<" "<<a[i].l<<" "<<a[i].t<<endl;
//		cout<<"=====\n";
//		dp[0] = a[0].h;
		for(int i=0; i<n; i++) {
			for(int j=maxt; j>=a[i].l; j--) {
				if(a[i].t < j)	continue;
				dp[j] = max(dp[j], dp[j-a[i].l] + a[i].h);
				ans = max(ans, dp[j]);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
