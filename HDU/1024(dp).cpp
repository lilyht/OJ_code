#include <stdio.h>
#include <cmath> 
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
//language: G++ 
/* 参考 https://blog.51cto.com/13688928/2117013
 * dp[i][j]表示在前j个数中，以a[j]结尾并分为i段的最大和
 * 状态转移公式：dp[i][j] = max(dp[i-1][k], dp[i][j-1]) + a[j]
 * 分别表示 a[j] 单独成段和 a[j] 加入以 a[j-1] 结尾的一段
 */
int a[1000005];
int dp[1000005];
int maxx[1000005];

int main() {
	int m, n;
	while(~scanf("%d%d", &m, &n)) {
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		memset(maxx, 0, sizeof(maxx));
		
		int maxsum;
		for(int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		for(int i=1; i<=m; i++) {
			maxsum = -99999999;
			for(int j=i; j<=n; j++) {
				dp[j] = max(dp[j-1], maxx[j-1]) + a[j];
				maxx[j-1] = maxsum;  //这里为什么这么写，后面注释掉的写法有什么不同？不太理解 
				maxsum = max(maxsum, dp[j]);
//				maxx[j] = maxsum;
			}
		}
		printf("%d\n", maxsum);
	} 
	return 0;
} 
