#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
using namespace std;
#define INF 99999999
//2020-08-13 16:22:47	Accepted	4460	421MS	5760K	1484 B	G++
int n, m;
string s, t;
int name[1005];
bool vis[1005];
map<string, int> mp;
int dis[1005][1005];
vector<int> G[1005];
queue<int> Q;

int bfs(int x) {
	memset(vis, 0, sizeof(vis));
	while(!Q.empty())	Q.pop();
	Q.push(x);
	dis[x][x] = 0;
	vis[x] = 1;
	while(!Q.empty()) {
		int y = Q.front();
		Q.pop();
		int sz = G[y].size();
		for(int i=0; i<sz; i++) {
			int v = G[y][i];
			if(!vis[v]) {
				Q.push(v);
				vis[v] = 1;
				if(dis[x][v] > dis[x][y] + 1) {  //理解 
//					cout<<"x: "<<x<<" y: "<<y<<" i: "<<i<<", G[y][i]: "<<G[y][i]<<endl;
					dis[x][v] = dis[x][y] + 1;
//					cout<<["[G[y][i]]: "<<G[y][i]]<<endl; 
				}
				
			}
		}
	}
}

int main() {
	while(cin>>n && n) {
		mp.clear();
		for(int i=0; i<n; i++) {
			cin>>s;
			mp[s] = i;
			G[i].clear();
		}
		cin>>m;
		for(int i=0; i<m; i++) {
			cin>>s>>t;
			G[mp[s]].push_back(mp[t]);
			G[mp[t]].push_back(mp[s]);  //双向的关系
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++)
				dis[i][j] = INF;
		}
			
		for(int i=0; i<n; i++)
			bfs(i);
		
		int ans = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
                ans = max(ans, dis[i][j]);
        if(ans != 99999999)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
	}
	
	return 0;
}
