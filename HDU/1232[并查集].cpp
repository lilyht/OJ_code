#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//并查集：注意，要从1开始而不是0
 
int n, m, a, b;
int f[1005];

void init(int n) {
	for(int i=1; i<=n; i++) {
		f[i] = i;
	}
}

int find(int x) {
	if(x == f[x])
		return x;
	return f[x] = find(f[x]);
}

void Union(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if(fa == fb)
		return;
	f[fa] = fb;
}

int main() {
	while(scanf("%d", &n)) {
		if(n == 0)	break;
		scanf("%d", &m);
		init(n);
		for(int i=0; i<m; i++) {
			scanf("%d%d", &a, &b);
			Union(a, b);
		}
		
		int ans = 0;  //集合个数 
		for(int i=1; i<=n; i++) {
			if(f[i] == i)	ans++;
		}
			
		printf("%d\n", ans-1);
	}
	return 0;
} 
