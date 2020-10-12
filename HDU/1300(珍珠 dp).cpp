#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 110;
//2020-09-18 23:34:14	Accepted	1300	0MS	1392K	812B	G++ 
int a[MAXN];  //每种珍珠需要的数量 
int p[MAXN];  //每种花珍珠的价格 
int sum[MAXN];  //前i种珍珠的总数目 
int dp[MAXN];
int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		memset(sum, 0, sizeof(sum));
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>p[i];
			sum[i] = sum[i-1] + a[i];
		}
		//dp[i][j]的第一维代表选到第i种珍珠了
		//第二维j可取1~i，代表从第j种开始，买的是价高的那种珍珠
		//转移方程：dp[i] = min(dp[i], dp[j] + p[i]*(10 + sum[i]-sum[j])) 
		dp[0] = 0;
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=i; j++) {  //注意：j是从0开始而不是1开始！！ 
				dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j] + 10)*p[i]);
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
