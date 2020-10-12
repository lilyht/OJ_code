#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 100005;
const int MAXM = 10005;
//2020-08-31 17:16:06	Accepted	1203	31MS	1836K	554 B	C++ 
int w[MAXM];
double v[MAXN];
double dp[MAXN];

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m) && n+m) {
		for(int i=0; i<m; i++) {
			scanf("%d%lf", &w[i], &v[i]);
		}
		for(int i=0; i<=n; i++)
			dp[i] = 1.0;
		//01背包 
		for(int i=0; i<m; i++) {
			for(int j=n; j>=w[i]; j--) {
				dp[j] = min(dp[j], dp[j-w[i]]*(1-v[i]));  //失败的概率，越小越好 
			}
		}
		printf("%.1f%%\n", (1-dp[n])*100);
	}
	
	return 0;
}
