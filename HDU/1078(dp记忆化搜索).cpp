#include <iostream>
#include <cstring>
using namespace std;

int m[105][105];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dp[105][105];
int n, k;

int dfs(int x, int y) {
	//停下来的条件是什么呢？ 是这个子问题的答案以及算出来过了 
	if(dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = m[x][y];
	
	for(int step=1; step<=k; step++) {  //最多走k步 
		for(int i=0; i<4; i++) {  //四个方位 
			int x_ = x + dx[i]*step;
			int y_ = y + dy[i]*step;
			if(x_<=n && x_>0 && y_<=n && y_>0 && m[x_][y_] > m[x][y]) {
				dp[x][y] = max(dp[x][y], m[x][y] + dfs(x_, y_));
			}
		}
	}
	return dp[x][y];
}

int main() {
	while(cin>>n>>k) {
		if(n == -1 && k == -1)	break;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				cin>>m[i][j];
			}
		}
		memset(dp, -1, sizeof(dp));
		cout<<dfs(1, 1)<<endl;
	} 
	return 0;
} 
