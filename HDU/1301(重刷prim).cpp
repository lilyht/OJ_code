#include <iostream>
#include <string.h>
using namespace std;
//2020-09-07 17:29:40	Accepted	1301	0MS	1400K	1021 B	G++
const int inf = 999999999;
int mp[30][30];
int d[30];
int vis[30];

int main() {
	int n, k, cost;
	char src, dest;
	while(cin>>n && n) {
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				mp[i][j] = inf;
		for(int i=1; i<=n; i++)
			d[i] = inf;
		for(int i=1; i<n; i++) {
			cin>>src>>k;
			for(int j=0; j<k; j++) {
				cin>>dest>>cost;
				mp[src-'A'+1][dest-'A'+1] = cost;
				mp[dest-'A'+1][src-'A'+1] = cost;
			}
		}
		//prim
		int ans = 0;
		memset(d, 0, sizeof(d));
		for(int i=1; i<=n; i++)
			d[i] = mp[1][i];
		memset(vis, 0, sizeof(vis));
		//把第一个节点放进去 
		vis[1] = 1;
		d[1] = 0;
		int x;
		for(int i=2; i<=n; i++) {
			int temp = inf;
			for(int j=1; j<=n; j++) {
				if(!vis[j] && temp > d[j]) {
					x = j;
					temp = d[j];
				}
			}
			vis[x] = 1;
			ans += temp;
			for(int j=1; j<=n; j++) {  //更新其他点 
				if(!vis[j] && d[j] > mp[x][j]) {
					d[j] = min(d[j], mp[x][j]);
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
