#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
//Dijkstra
//2020-08-23 10:36:17	Accepted	1874	31MS	1488K	1133 B	G++
//对于每组数据，请在一行里输出最短需要行走的距离。如果不存在从S到T的路线，就输出-1.

const int MAXN = 2005;
const int INF = 0x7ffffff;
int f[MAXN];
int d[MAXN];
bool vis[MAXN];

struct edge{
	int to;
	int cost;
};
vector<edge> G[MAXN];

int main() {
	int n, m, a, b, c, x, y;
	while(cin>>n>>m) {
		//init
		for(int i=0; i<n; i++) {
			f[i] = i;
			vis[i] = 0;
			d[i] = -1;  //-1表示不可达 
			G[i].clear();  //清空邻接链表 
		}
		//input
		for(int i=0; i<m; i++) {
			cin>>a>>b>>c;
			edge e;
			e.cost = c;
			e.to = b;
			G[a].push_back(e);
			e.to = a;
			G[b].push_back(e);
		}
		cin>>x>>y;
		if(x == y) {
			cout<<0<<endl;
			continue;
		}
		int P = x;
		vis[x] = 1;
		d[x] = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<G[P].size(); j++) {
				int t = G[P][j].to;
				int w = G[P][j].cost;
				if(vis[t])	continue;
				if(d[t] == -1 || d[t] > d[P] + w) {
					d[t] = d[P] + w;
				}
			}
			int minw = 1000000005;
			for(int j=0; j<n; j++) {
				if(!vis[j]) {
					if(d[j] == -1)	continue;
					if(d[j] < minw) {
						minw = d[j];
						P = j;
					}
				}
			}
			vis[P] = 1;
		}
		cout<<d[y]<<endl;
	} 
	return 0;
}
