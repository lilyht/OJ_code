#include <iostream>
#include <string.h>
using namespace std;
//2020-08-16 11:32:02	Accepted	2602	62MS	1412K	445 B	G++
//dp
int t;
int v[1005];
int w[1005];
int dp[1005];

int main() {
	cin>>t;
	while(t--) {
		int n, V;
		cin>>n>>V;
		for(int i=1; i<=n; i++)	cin>>v[i];  //价值 
		for(int i=1; i<=n; i++)	cin>>w[i];  //体积 
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++) {
			for(int j=V; j>=w[i]; j--) {
				dp[j] = max(dp[j], dp[j-w[i]] + v[i]);  //注意是倒序的
				/* 
				 * 要求在每次主循环中以v=V..0的顺序推dp[v]， 
				 * 这样才能保证推dp[v]时，dp[v-c[i]]保存的是状态 dp[i-1][v-c[i]]的值。
				 */ 
			}
		}
		cout<<dp[V]<<endl;
	}
	return 0;
}
