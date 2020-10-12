#include <iostream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1005;
int i, j, k, m, n;
int indegree[maxn], t[maxn];

struct node {
	int to, val;
};
vector<node> G[maxn];

int main() {
	std::ios::sync_with_stdio(false);
	while (cin>>n>>m) {
		// ‰»Î 
		int u, v, w;
		for(i=0; i<n; i++) {
			indegree[i] = 0;
			t[i] = 0;
			G[i].clear();
		}
		for(i=1; i<=m; i++) {
			cin>>u>>v>>w;
			node N;
			N.to = v;
			N.val = w;
			G[u].push_back(N);
			indegree[v]++;
		}
		//Õÿ∆À≈≈–Ú 
		queue<int> Q;
		for(i=0; i<n; i++) {
			if(indegree[i] == 0) {
				Q.push(i);
				t[i]++;
			}
		}
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			for (i=0; i<G[u].size(); i++) {
				int v = G[u][i].to;
				int w = G[u][i].val;
				t[v] = max(t[v], t[u]+w);  //º«¬º ve 
				if (--indegree[v] == 0)
					Q.push(v);
			}
		}
		// ‰≥ˆ 
		int ans = 0;
		for(i=0; i<n; i++)
			ans = max(ans, t[i]);
		cout<<ans<<endl;
	}
	return 0;
}
