//树型DP 
#include <cstdio>
#include <cstring>
using namespace std;
int dp[105][105];  //在第i个洞穴有j个人时获得的最大值
int mapt[105][105];
int n, m;

struct node{
	int brain, bug;
} room[105];

int max(int x, int y){
	return x>y?x:y;
}

void dfs(int x, int pre){
	int cost = (room[x].bug+19)/20;  //第x个洞需要的人数
	for(int i=m; i>=cost; --i)
		dp[x][i] = room[x].brain;
	for(int i=1; i<=n; ++i){
		if(mapt[x][i] && pre!=i){
			dfs(i, x);
			for(int j=m; j>=cost; --j)
				for(int k=1; k<=j-cost; ++k)
					dp[x][j] = max(dp[x][j], dp[x][j-k]+dp[i][k]);  //这里有点懵 
		}
	}
}

int main(){
	int a, b;
	while(1){
		scanf("%d%d",&n,&m);
		if(n == -1 && m == -1) break;
		for(int i=1; i<=n; ++i)
			scanf("%d%d", &room[i].bug, &room[i].brain);
		memset(mapt, 0, sizeof(mapt));
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<n; ++i){
			scanf("%d%d", &a, &b);
			mapt[a][b] = mapt[b][a] = 1;
		}
		if(m == 0){
			printf("0\n");
			continue;
		}
		dfs(1, -1);
		printf("%d\n", dp[1][m]);
	}
	
	return 0;
}
