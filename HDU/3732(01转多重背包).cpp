#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
//2020-08-17 12:25:58	Accepted	3732	249MS	2544K	1046 B	G++
//0-1背包超时、转多重背包、从0-1背包转多重背包

char str[15];
int cnt[15][15];
int V[100005];
int C[100005];
int dp[100005];

int main() {
	int N, C1, v, c;
	while(~scanf("%d%d", &N, &C1)) {
		memset(cnt, 0, sizeof(cnt));
		memset(C, 0, sizeof(C));
		memset(V, 0, sizeof(V));
		
		for(int i=1; i<=N; i++) {
			scanf("%s%d%d", str, &v, &c);
			cnt[v][c]++;
		}
		//分组
		int index = 0;
		for(int i=0; i<=10; i++) {
			for(int j=0; j<=10; j++) {
				if(cnt[i][j] == 0)	continue;
				else {
					int r = 1;
					while(cnt[i][j] > r) {
						cnt[i][j] -= r;
						C[++index] = r * j;
						V[index] = r * i;
						r = r << 1;
					}
					if(cnt[i][j] > 0) {
						C[++index] = cnt[i][j] * j;
						V[index] = cnt[i][j] * i;
					}
				}
			}
		}
		//多重背包
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=index; i++) {
			for(int j=C1; j>=C[i]; j--) {
				dp[j] = max(dp[j], dp[j-C[i]] + V[i]);
			}
		}
		printf("%d\n", dp[C1]);
	}
	
	return 0;
}
