#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;

int n, m, a, b, kse = 0;
int f[1200000];
int vis[1200000];

char op[5];

int find(int x) {
	int a = x;
	while(x != f[x]) {
		x = f[x];
	}
	//路径压缩
	while(a != f[a]) {
		int z = a;
		a = f[a];
		f[z] = x;
	}
	return x;
}

void Union(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if(fa == fb)
		return;
	f[fa] = fb;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(n == 0 && m == 0)	break;
		kse++;
		int ans = 0;
		memset(f, 0, sizeof(f));
		memset(vis, 0, sizeof(vis));

		//建立虚拟节点
		for(int i=0; i<n; i++)	f[i] = i + n;  // 这样处理的目的是将 0 -> N-1 的节点处理成叶子节点
		for(int i=n; i<2*n+m+1; i++)	f[i] = i;
		int cnt = 2*n; 
		
		//input
		for(int i=0; i<m; i++) {
			scanf("%s", &op);
			if(op[0] == 'M') {
				scanf("%d%d", &a, &b);
				Union(a, b);
			}
			if(op[0] == 'S') {
				scanf("%d", &a);
				f[a] = cnt++;
			}
			
		}
		for(int i=0; i<n; i++) {
            int tmp = find(i);
            if(vis[tmp] == 0) {
                vis[tmp] = 1;
                ans++;
            }		
		}
		printf("Case #%d: %d\n", kse, ans);

	}
	return 0;
} 
