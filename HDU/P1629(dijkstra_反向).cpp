#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int MAX_N = 1005 * 2;
const int INF = 0x3f3f3f3f;
int n, m, u, v, w;
int vis[MAX_N];
int dis[MAX_N];

struct edge {
	int to, cost;
	edge(int tt, int tc) : to(tt), cost(tc) {};
};
vector<edge> G[MAX_N];

void dijkstra(int start) {
	fill(dis, dis+n+n+2, INF);
	priority_queue<P, vector<P>, greater<P> > Q;
	dis[start] = 0;
	Q.push(P(0, start));
	while(!Q.empty()) {
		P p = Q.top();
		Q.pop();
		int v = p.second;
		if(dis[v] < p.first)	continue;
		for(int i=0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if(dis[e.to] > dis[v] + e.cost) {
				dis[e.to] = dis[v] + e.cost;
				Q.push(P(dis[e.to], e.to));
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	//init
	memset(vis, 0, sizeof(vis));
	
	for(int i=0; i<m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back(edge(v, w));
		G[v+n].push_back(edge(u+n, w));  //用于反向图 
	}
	long long ans = 0;
	dijkstra(1);
	for(int i=2; i<=n; i++)	ans += dis[i];  //去的代价 
	dijkstra(1+n);
	for(int i=2+n; i<=2*n; i++)	ans += dis[i];  //回的代价 
	
	printf("%lld", ans);
	return 0;
}
