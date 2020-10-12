#include <stdio.h>
int dp[10005]= {0};
//2020-08-22 16:48:21	Accepted	1231	124MS	1256K	494 B	G++
int main() {
	int n, max, l, r, p;
	while(~scanf("%d", &n) && n) {
		max = -0x7fffffff;
		r = 0;
		p = 1;
		for(int i=1; i<=n; i++) {
			scanf("%d", &dp[i]);
			if(dp[i-1] > 0)
				dp[i] += dp[i-1];
			else
				p = i;
			if(dp[i] > max) {
				max = dp[i];
				l = p;
				r = i;
			}
		}
		if(max < 0)
			printf("0 %d %d\n", dp[1], dp[n]);
		else if(max == 0)
			printf("0 0 0\n");
		else printf("%d %d %d\n", max, dp[l], dp[r] - dp[r-1]);
	}
	return 0;
}
