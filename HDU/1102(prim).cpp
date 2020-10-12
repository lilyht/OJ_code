#include <iostream>
#include <string.h>
using namespace std;
//prim
//2020-09-16 20:34:25	Accepted	1102	93MS	1452K	831 B	G++
const int MAXN = 110;
const int INF = 999999999;

bool vis[MAXN];
int d[MAXN];
int a[MAXN][MAXN];

int main() {
	int n, q, u, v;
	while(cin>>n) {
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				cin>>a[i][j];
		cin>>q;
		while(q--) {
			cin>>u>>v;
			a[u][v] = 0;
			a[v][u] = 0;
		}
		//init
		for(int i=0; i<=n; i++)
			d[i] = a[1][i];
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		//prim
		int x;
		int ans = 0;
		for(int i=1; i<n; i++) {
			int tmp = INF;
			for(int j=1; j<=n; j++) {
				if(!vis[j] && d[j] < tmp) {
					tmp = d[j];
					x = j;
				}
			}
			vis[x] = 1;
			ans += tmp;
			for(int j=1; j<=n; j++) {
				if(vis[j])	continue;
				if(d[j] > a[x][j]) {
					d[j] = min(d[j], a[x][j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
