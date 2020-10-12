#include "bits/stdc++.h"
//6787
//参考1：https://blog.csdn.net/CodaChan/article/details/107784774
//参考2：https://www.codetd.com/article/11515278 
//2020-09-15 11:10:45	Accepted	6787	78MS	48568K	882 B	G++ 
using namespace std;
const int mod = 1e9+7;
const int maxn = 1001;
int cas, n, m;
long long dp[maxn][maxn][11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	n = m = 1000;
	dp[1][0][0] = 1;
	for(int i=2; i<=n; ++i)
		for(int j=0; j<=min(i - 1, m); ++j) {
			long long tmp = 0;
			for(int k=1; k<=min(j, 10); ++k) {
				//第i格放门
				dp[i][j][k] = dp[i-1][j-1][k-1] * (i - 1);  //乘(i+1) 的意思是，这第i位上的传送器传送的目标位置可以是前面i-1个位置 
				dp[i][j][k] %= mod;
				//第i格不放门
				tmp += dp[i-1][j][k];
				tmp %= mod;
			}
			dp[i][j][0] = tmp + dp[i-1][j][0];
			dp[i][j][0] %= mod;
		}
	cin>>cas;
	while(cas--) {
		cin>>n>>m;
		if(!dp[n][m][0])
			cout<<"-1"<<endl;
		else
			cout<<dp[n][m][0]<<endl;
	}
}

