#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 5005;
//2020-09-06 12:37:17	Accepted	1500	280MS	21104K	609 B	G++ 
int a[MAXN];
int dp[1005][MAXN];
int main() {
	int t, k, n;
	cin>>t;
	while(t--) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		cin>>k>>n;
		for(int i=n; i>=1; i--) {
			cin>>a[i];
		}
		//dp[i][j]表示搜到了第i组的第j根筷子           n                       ..
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		for(int i=1; i<=n; i++)	dp[0][i] = 0;
		for(int i=1; i<=k+8; i++) {  //i代表第i组筷子 
			for(int j=3*i; j<=n; j++) {
				dp[i][j] = min(dp[i][j-1], dp[i-1][j-2] + (a[j]-a[j-1])*(a[j]-a[j-1]));
			}
		}
		cout<<dp[k+8][n]<<endl;
	}
	
	return 0;
}
