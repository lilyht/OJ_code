#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int MAXN = 1005;
//欧拉回路
//http://acm.hdu.edu.cn/showproblem.php?pid=1878 
//2020-08-24 16:13:48	Accepted	1878	78MS	1404K	980 B	G++
int indegree[MAXN];
int f[MAXN];
//vector<node> G;

int find(int x) {
	if(x == f[x])	return x;
	return f[x] = find(f[x]);
}

void Union(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) 
		f[fx] = fy;
}

int main() {
	int n, m, u, v;
	while(~scanf("%d", &n)) {
		if(n == 0)	break;
		int cnt = 0;
		memset(indegree, 0, sizeof(indegree)); 
		for(int i=1; i<=n; i++)	f[i] = i;
		scanf("%d", &m);
		for(int i=0; i<m; i++) {
			scanf("%d%d", &u, &v);
			indegree[u]++;
			indegree[v]++;
			Union(u, v); 
		}
		bool flag = 0;
		int num = 0;
		for(int i=1; i<=n; i++) {
			if(indegree[i] & 1) {
				//奇顶点
				flag = 1;
				break;
			}
		}
		if(flag == 1) {
			cout<<0<<endl;
			continue;
		}
		else {
			//连通？ 
			for(int j=1; j<=n; j++) {
				if(f[j] == j)
					num++; 
			}
			if(num == 1)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}
	
	return 0;
} 
