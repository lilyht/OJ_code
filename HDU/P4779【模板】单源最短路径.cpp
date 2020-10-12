#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int inf = 0x3f3f3f3f;

struct node {
	int to;
	int w;
};

int d[100005];
typedef pair<int, int> P;  //pair的第一维是当前最短距离，第二维是节点编号int d[100005];
vector<node> G[100005];

int main() {
	int n, m, s, u, v, w;
	cin>>n>>m>>s;  //s是起点 
	for(int i=0; i<=n; i++)	d[i] = inf, G[i].clear();
	for(int i=0; i<m; i++) {
		cin>>u>>v>>w;
		node e;
		e.to = v;
		e.w = w;
		G[u].push_back(e);
	}
	priority_queue<P, vector<P>, greater<P> > Q;
	while(!Q.empty())	Q.pop();
	Q.push(P(0, s));
	d[s] = 0; 
	while(!Q.empty()) {
		P p = Q.top();
		Q.pop();
		int v = p.second;  //节点编号 
		if(d[v] < p.first)	continue;
		for(int j=0; j<G[v].size(); j++) {
			node nd = G[v][j];
			if(d[nd.to] > d[v] + nd.w) {
				d[nd.to] = d[v] + nd.w;
				Q.push(P(d[nd.to], nd.to));
			}
		}
	}
	for(int i=1; i<n; i++)
		cout<<d[i]<<" ";
	cout<<d[n]<<endl;
	
	return 0;
}
