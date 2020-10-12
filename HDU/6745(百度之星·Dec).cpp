#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1005;
//2020-09-14 10:52:46	Accepted	6745	670MS	5328K	542 B	G++
//用scanf，否则超时 
int dp[MAXN][MAXN];

int gcd(int x, int y) {
	if(y == 0)	return x;
	return gcd(y, x%y);
}

int main() {
	int t, a, b;
	scanf("%d", &t);
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=1000; i++) {
		for(int j=1; j<=1000; j++) {
			if(gcd(i, j) == 1) {
				//质数
				 dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
			}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	while(t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", dp[a][b]);
	} 
	return 0;
} 
