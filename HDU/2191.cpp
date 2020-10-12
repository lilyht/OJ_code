#include <iostream>
#include <string.h>
using namespace std;
//多重背包
//2020-08-16 17:07:58	Accepted	2191	15MS	1420K	741 B	G++
int p[105], h[105], c[105];
int pp[1005], hh[1005], cc[1005];
int dp[105];

int main() {
	int t, n, m, x;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		for(int i=1; i<=m; i++) {
			cin>>p[i]>>h[i]>>c[i];
		}
		//分组 
		int cnt = 0;
		for(int i=1; i<=m; i++) {
			int r = 1;
			while(c[i] > r) {
				c[i] -= r;
				pp[++cnt] = p[i] * r;
				hh[cnt] = h[i] * r;
				r = r << 1;
			}
			if(c[i] > 0) {
				pp[++cnt] = p[i] * c[i];
				hh[cnt] = h[i] * c[i];
			}
		}
//		cout<<cnt<<endl;
		//dp
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=cnt; i++) {
			for(int j=n; j>=pp[i]; j--) {
				dp[j] = max(dp[j], dp[j-pp[i]] + hh[i]);
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
} 
