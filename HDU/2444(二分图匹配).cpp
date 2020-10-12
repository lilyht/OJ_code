#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
using namespace std;
//看的网上的代码 
//2020-09-13 19:50:25	Accepted	2444	78MS	5316K	1366 B	G++ 
typedef long long int LL;
const int maxn = 1000;
int g[maxn][maxn], used[maxn], link[maxn];
int color[maxn];
int nx, ny, n, m;

//二分匹配 
bool dfs(int u) {
	for(int v = 1; v <= n; v++) {
		if(g[u][v] && !used[v]) {
			used[v] = 1;
			if(link[v] == -1 || dfs(link[v])) {
				link[v] = u;
				return true;
			}
		}
	}
	return false;
}

int maxmatch() {
	int res = 0;
	memset(link, -1, sizeof(link));
	for(int i=1; i<=n; i++) {
		memset(used, 0, sizeof(used));
		if(dfs(i))	res++;
	}
	return res / 2;  //最后答案是我们算的最大匹配数的一半 
}

bool dye(int u) {
	for(int v=1; v<=n; v++) {
		if(g[u][v]) {
			if(color[v] == -1) {
				color[v] = !color[u];
				if(!dye(v))
					return false;
			}
			else if(color[v] == color[u])
				return false;
		}
	}
	return true;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		memset(g, 0, sizeof(g));
		for (int i=0; i<m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u][v] = g[v][u] = 1;
		}
		
		memset (color, -1, sizeof (color));
		int ok = 1;
		for (int i=1; i<=n; i++) {  //染色，可能不止一个连通分量
			if(color[i] == -1) {
				color[i] = 1;
				if(!dye(i)) {
					ok = 0;
					break;
				}
			}
		}
		if (ok) printf ("%d\n", maxmatch ());
		else printf ("No\n");
	}
	return 0;
}
