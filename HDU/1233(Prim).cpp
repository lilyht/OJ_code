#include <iostream>
#include <string.h>
using namespace std;
#define INF 0x7fffffff
/*
 * 2020-08-08 09:53:49	Accepted	1233	967MS	1456K	953B	G++
 */ 
int mp[105][105];
int vis[105];
int d[105];

int main() {
	int n, a, b, cost;
	while(cin>>n && n) {
		//init
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<=n; i++)	d[i] = INF;
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
				mp[i][j] = INF;
		//cin & store
		for(int i=0; i<n*(n-1)/2; i++) {
			cin>>a>>b>>cost;
			mp[a][b] = mp[b][a] = cost;
		}
		//put node 1 into set
		vis[1] = 1;
		d[1] = 0;
		//这里。。。又忘了写 *** 
		for(int i=0; i<=n; i++)	d[i] = mp[i][1];
		//遍历 
		int ans = 0;
		int x = 0;
		for(int i=1; i<n; i++) {
			int temp = INF;
			for(int j=1; j<=n; j++) {
				if(!vis[j] && d[j] < temp) {
					temp = d[j];
					x = j;
				}
			}
			//update this node's states
			vis[x] = 1;
			ans += temp;
			//update other nodes
			for(int j=1; j<=n; j++)
				if(!vis[j])
					d[j] = min(mp[x][j], d[j]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
