#include <iostream>
#include <string.h>
using namespace std;
//2020-09-16 20:07:26	Accepted	1081	15MS	1452K	563 B	G++	
int a[110][110];
int b[110];
int dp[110];
int main() {
	int n;
	while(cin>>n) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				cin>>a[i][j];
			}
		}
		int ans = 0;
		for(int i=1; i<=n; i++) {
			memset(b, 0, sizeof(b));
			for(int j=i; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					b[k] += a[j][k];
				}
				memset(dp, 0, sizeof(dp));
				for(int k=1; k<=n; k++) {
					dp[k] = max(dp[k], dp[k-1] + b[k]);
					ans = max(ans, dp[k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
