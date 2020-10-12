#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 
int a[101], c[101];
int dp[100001];
int w[1001];

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m), n+m){
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		memset(dp, 0, sizeof(dp));  //初始化状态0为可达 
		dp[0] = 1;
		for(int i=0; i<n; i++)	scanf("%d", &a[i]);  //硬币价值 
		for(int i=0; i<n; i++)	scanf("%d", &c[i]);  //硬币数量 
		int x = 0;
		int cnt = 0;
		//每种硬币分组 
		for(int i=0; i<n; i++){
			for(int j=1; c[i]>0; j *= 2){
				x = min(j, c[i]);
				c[i] -= x;
				w[cnt++] = a[i]*x;  //该分组的硬币价值 为单个价值乘上组中物品数量x 
			}
		}
		//转化为0/1背包问题求解 
		for(int i=0; i<cnt; i++){
			for(int j=m; j>=w[i]; j--){
				if(dp[j-w[i]])	//如果j-w[i]状态是可达的，则进行转移 
					dp[j] = 1;
			}
		}
		int ans = 0;
		for(int i=1; i<=m; i++){
			ans += dp[i];
		}
		printf("%d\n", ans);
		
	}
	
	return 0;
}
