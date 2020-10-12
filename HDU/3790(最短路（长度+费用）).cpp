#include <iostream>
#include <vector>
#include <string.h> 
using namespace std;
//dijkstra    14:56——16:02
//2020-09-15 16:02:19	Accepted	3790	187MS	2744K	1451 B	G++  
const int MAXN = 1010;

int d[MAXN];
int cst[MAXN]; 
bool vis[MAXN];

struct node {
	int to;
	int w;
	int cost;
};
vector<node> G[MAXN];

int main() {
	int n, m, st, ed, a, b, d_, p;
	while(~scanf("%d%d", &n, &m) && n+m) {
		//init
		for(int i=1; i<=n; i++)	d[i] = -1;  //不可达
		memset(vis, 0, sizeof(vis));
		memset(cst, 0, sizeof(cst));
		for(int i=0; i<=n; i++)	G[i].clear();
		
		for(int i=0; i<m; i++) {
			scanf("%d%d%d%d", &a, &b, &d_, &p);
			node e;
			e.to = b;
			e.w = d_;
			e.cost = p;
			G[a].push_back(e);
			e.to = a;
			G[b].push_back(e);
		}
		scanf("%d%d", &st, &ed);
	
		//Dijkstra
		int P = st;
		vis[P] = 1;
		d[P] = 0;  //Attention!!! 
		int minc = 0x7fffffff;
		for(int i=1; i<n; i++) {
			for(int j=0; j<G[P].size(); j++) {
				int t = G[P][j].to;
				int c = G[P][j].cost;
				int w = G[P][j].w;
				if(vis[t])	continue;
				if(d[t] >= d[P] + w || d[t] == -1) {  //注意！！！就差一个等号！！！ 
					d[t] = d[P] + w;  //更新距离
					cst[t] = cst[P] + c;  //更新费用
					if(t == ed) {
						if(minc > cst[t]) {
							minc = cst[t];
						}
					}
				}
			}
			int minw = 0x7fffffff;
			for(int j=1; j<=n; j++) {
				if(!vis[j]) {
					if(d[j] == -1)	continue;
					if(d[j] < minw) {
						minw = d[j];
						P = j;
					}
				}
			}
			vis[P] = 1;  //选中P点 
		}
		printf("%d %d\n", d[ed], cst[ed]);
	}
	
	return 0;
} 
