//#include <iostream>
//#include <string.h>
//using namespace std;
////8:56--9:30 
//const int MAXN = 205;
//
//int x[MAXN], y[MAXN];
//int dp[110005];
//int main() {
//	int t, n, m, sum;
//	cin>>t;
//	while(t--) {
//		cin>>n>>m;
//		for(int i=0; i<110005; i++)
//			dp[i] = 999999999;
//		sum = 0;
//		for(int i=1; i<=n; i++) {
//			cin>>x[i]>>y[i];
//			sum += x[i];
//		}
//		//完全背包
//		dp[0] = 0;
//		for(int i=1; i<=n; i++) {
//			for(int j=x[i]; j<=m+sum; j++) {
//				dp[j] = min(dp[j], dp[j-x[i]] + y[i]);
//			}
//		}
//		int ans = 999999999;
//		for(int i=m; i<=m+sum; i++) {
//			if(dp[i] < ans) {
//				ans = dp[i];
//			}
//		}
//		cout<<ans<<endl;
//	}
//	return 0;
//}
#include<iostream>
#include<algorithm>
using namespace std;
//2020-09-14 09:29:35	Accepted	6743	31MS	1404K	1002 B	G++
//这也太坑了，不是完全背包是直接暴力啊啊啊 
int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, m, ans = (int)1e9;
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			int x, y;
			cin>>x>>y;
			if(m%x == 0)
				ans = min(ans, m/x*y);
			else
				ans = min(ans, (m/x+1)*y);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
