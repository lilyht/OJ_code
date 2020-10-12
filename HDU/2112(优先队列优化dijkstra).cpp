#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>  //fill函数的头文件
using namespace std;

//HDU	Accepted	2112	3151MS	2160K	1413 B	G++
const int MAX_N = 10010;
const int INF = 0x3f3f3f3f;
 
typedef pair<int, int> P;

struct edge {
	int to, cost;
	edge(int tt, int tc) : to(tt), cost(tc){};
};
vector<edge> G[MAX_N];
map<string, int> mp;
int n, cost;

int Dijkstra(int st, int ed) {
	int dis[MAX_N];
	fill(dis, dis+n+1, INF);
	//优先队列
	priority_queue < P, vector<P>, greater<P> > Q;
	dis[st] = 0;
	Q.push(P(0, st));
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
	return dis[ed];
}

int main() {
	string st, ed, s, e;
	while(~scanf("%d", &n) && n != -1) {
		mp.clear();
		for(int i=0; i<MAX_N; i++)	G[i].clear();
		int cnt = 1;
		cin>>st>>ed;
		mp[st] = cnt++;
		mp[ed] = cnt++;

		for (int i=0; i<n; i++) {
			cin>>s>>e>>cost;
			if(!mp[s])	mp[s] = cnt++;
			if(!mp[e])	mp[e] = cnt++;
			//双向
			G[mp[s]].push_back(edge(mp[e], cost));
			G[mp[e]].push_back(edge(mp[s], cost));  //原来是这里！！！ 
		}
		int res = Dijkstra(mp[st], mp[ed]);
		if(res == INF)
			printf("-1\n");
		else
			printf("%d\n", res);
	}
	return 0;
}
