#include <stdio.h>
#define N 30001
//2020-08-19 17:53:39	Accepted	1257	31MS	1220K	557 B	G++
/*
�����ǰ���� i �ĸ߶� > ǰ��ĵ��� j �ĸ߶�,
��ô���ص�ǰ���� i ��ϵͳ,һ�������� j �ĺ����ϵͳ
*/

int a[N], dp[N];
int max(int a, int b) {
	return a>b ? a : b;
}

int main() {
	int n, i;
	a[0] = N;
	while (scanf("%d", &n) != EOF) {
		for(i=1; i<=n; i++) {
			dp[i] = 1;
			scanf("%d", &a[i]);
		}
		for(i=1; i<=n; i++) {
			for (int j=1; j<=i; j++) {
				if(a[i] > a[j])
					dp[i] = max(dp[i], dp[j]+1);
			}
		}
		int ans = 0;
		for(i=1; i<=n; i++)
			ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}
