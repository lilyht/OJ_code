#include <iostream>
#include <string.h>
using namespace std;
#define INF 0x7fffffff	// 我哭了就因为这个初始化，过不去，0x3f太小了 

// Prim算法 

int n, k, cost;
char a, b;
int x = 0;
int d[30];
int vis[30];
int mp[30][30];  //代表两点间距离

int main() {
	while(cin>>n && n) {
		//init
		memset(vis, 0, sizeof(vis));
		for(int i=1; i<=n; i++)	d[i] = INF;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				mp[i][j] = INF;		
		
		for(int i=1; i<n; i++) {
			cin>>a>>k;
			for(int j=0; j<k; j++) {
				cin>>b>>cost;
				mp[a-'A'+1][b-'A'+1] = mp[b-'A'+1][a-'A'+1] = cost;
			}
		}
		//prim
		int ans = 0;
		vis[1] = 1;  //忘了 
		for(int i=1; i<=n; i++)  //忘了写所以wa 
			d[i] = mp[i][1];
			
		for(int i=1; i<n; i++) {  //note: 右边界是i<n，而不是 <= ，因为节点1已经加进来了 
			int m = INF; 
			for(int j=1; j<=n; j++)
				if(!vis[j] && d[j] < m)
					m = d[x = j];
			vis[x] = 1;
			ans += m;
			for(int j=1; j<=n; j++)
				if(!vis[j])
					d[j] = min(mp[j][x], d[j]);
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
