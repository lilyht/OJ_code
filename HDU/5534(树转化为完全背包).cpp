#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 2020;
//2020-09-18 19:44:23	Accepted	5534	187MS	1424K	889B	G++
int f[MAXN];
int dp[MAXN];
int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<n; i++)	cin>>f[i];
		//n个结点的树，n-1条边，即度数和为2n-2。
		//又因为每个结点的度数至少为1,所以先令每个结点的度数为1。剩下n-2的的度数再分配掉
		//度有[2, 3, ..., n-1]这些种类
		//消耗[1,...,n-2]
		//价值是[f(2),...,f(n-1)]
		//每一种度可以拿很多次，完全背包问题
		memset(dp, 0, sizeof(dp));
		dp[0] = f[1] * n;  //一开始将dp[0]初始化为所有的点都是一度顶点的总value值
		for(int i=2; i<=n-1; i++)  //从二度顶点到n-1度顶点开始循环dp
			for(int j=i-1; j<=n-2; j++)  //最多只有 n-2 个顶点可以进行调控
				dp[j] = max(dp[j], dp[j-i+1] + f[i] - f[1]);     //增添一个度数为i的顶点
				//一开始由于所有的顶点都是一度顶点，所以使用的cost是 i-1 ，而得到的value值是 f[i]-f[1]
		cout<<dp[n-2]<<endl;
	}
	return 0;
}
