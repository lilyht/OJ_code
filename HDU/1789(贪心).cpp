#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
//2020-09-17 08:39:24	Accepted	1789	93MS	1420K	785 B	G++
/*
 * 贪心策略：
 * 规则是：
 * 如果期限相同，对扣分多的从大到小排列，如果扣分相同，则将期限从小到大排列。
 * 最优策略：每门功课最好在给定的deadline当天就完成，如不能完成，只能往前找哪一天还没使用，尽量使得做这门功课的日期越大越好，
 * 即从其截止日期到第一天，如果一路遍历都已经被标记过了，到最后j==0说明已经没有足够的一天时间给他做这门功课，那么就将这门功课扣的分数加到ans中
 * 最终的ans即为最小扣分值
 */ 
//参考博客：https://www.cnblogs.com/acgoto/p/8526303.html 
bool vis[MAXN];
struct node{
	int ddl;
	int cost;
}a[MAXN];

bool cmp(node x, node y) {
	if(x.cost != y.cost)
		return x.cost > y.cost;
	else
		return x.ddl < y.ddl;
}

int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>a[i].ddl;
		}
		for(int i=0; i<n; i++) {
			cin>>a[i].cost;
		}
		sort(a, a+n, cmp);
//		for(int i=0; i<n; i++)
//			cout<<a[i].ddl<<" "<<a[i].cost<<endl;
		memset(vis, 0, sizeof(vis));
		int ans = 0;
		int j;
		for(int i=0; i<n; i++) {
			for(j=a[i].ddl; j>0; j--) {
				if(!vis[j]) {
					vis[j] = 1;
					break;
				}
			}
			if(j == 0)
				ans += a[i].cost;
		}
		cout<<ans<<endl;
	} 
	return 0; 
} 
