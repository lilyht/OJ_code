#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 2005;
const int MAXK = 1005;
//2020-09-06 13:11:32	Accepted	1421	265MS	8248K	622 B	G++
bool cmp(int x, int y) {
	return x > y;
}

int a[MAXN];
int dp[MAXK][MAXN];
int main() {
	int n, k;
	while(cin>>n>>k) {
		for(int i=1; i<=n; i++)
			cin>>a[i];
		sort(a+1, a+n+1, cmp);
		for(int i=1; i<=k; i++)
			for(int j=1; j<=n; j++)
				dp[i][j] = 0x3f3f3f3f;
		for(int i=1; i<=n; i++)
			dp[0][i] = 0;
		for(int i=1; i<=k; i++) {
			for(int j=2*i; j<=n; j++) {  //为什么j初始加1就不能过呢？ 
				dp[i][j] = min(dp[i][j-1], dp[i-1][j-2] + (a[j]-a[j-1])*(a[j]-a[j-1]));
			}
		}
		cout<<dp[k][n]<<endl;
	} 
	return 0;
} 
