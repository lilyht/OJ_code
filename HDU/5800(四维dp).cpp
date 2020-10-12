#include<stdio.h>
#include<string.h>
#define Mod 1000000007
typedef long long LL;
int a[1010];
int dp[1010][1010][3][3];
//定义dp[i][j][ii][jj]表示：前i个数中，和达到j，ii个必选，jj个必不选的情况数量。ii、jj范围为0-2，四重循环就可以了
/* 分两种：
　　1. 第i个数可选可不选，那么dp[i][j][ii][jj] += dp[i-1][j][ii][jj] + dp[i-1][j-a[i]][ii][jj]。
　　2. 又分两种：
　　　　1. 第i个数必选，dp[i][j][ii][jj] += dp[i-1][j-a[i]][ii-1][jj]。
　　　　2. 第i个数必不选，dp[i][j][ii][jj] += dp[i-1][j][ii][jj-1]。
 */
//https://www.cnblogs.com/hchlqlz-oj-mrj/p/5738480.html
//2020-09-12 11:16:34	Accepted	5800	1279MS	37144K	947 B	G++ 
void add(int &x,int y) {
	x = x+y;
	if(x >= Mod) x -= Mod;
}

int main() {
	int t, n, m;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		memset(dp, 0, sizeof(dp));
		dp[0][0][0][0] = 1;
		for(int i=1; i<=n; i++) {
			for(int j=m; j>=0; j--) {
				for(int ii=2; ii>=0; ii--) {
					for(int jj=2; jj>=0; jj--) {
						add(dp[i][j][ii][jj], dp[i-1][j][ii][jj] );
						if(j + a[i] <= m)	add(dp[i][j+a[i]][ii][jj], dp[i-1][j][ii][jj] );
						
						if(ii > 0 && j+a[i] <= m)	add(dp[i][j+a[i]][ii][jj], dp[i-1][j][ii-1][jj] );  //第i个数必选 
						if(jj > 0)	add(dp[i][j][ii][jj], dp[i-1][j][ii][jj-1] );  //第i个数必不选 
					}
				}
			}
		}
		LL ret = 0;
		for(int i=2; i<=m; i++) {
			ret = ret + dp[n][i][2][2];
		}
		printf("%I64d\n", ret*2*2%Mod);
	}
	return 0;
}
