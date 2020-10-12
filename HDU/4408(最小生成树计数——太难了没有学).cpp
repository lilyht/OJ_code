#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int f[105];

struct edge{
	int x, y;
	int dis;
}p[1005];

bool cmp(edge a, edge b) {
	return a.dis < b.dis;
}

int find(int x) {
	if(x == f[x])	return x;
	return f[x] = find(f[x]);
}

int main() {
	int n, m, p;
	while(~scanf("%d%d%d", &n &m, &p) && n+m+p) {
		for(int i=0; i<m; i++) {
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].dis);
		}
		//init 
		for(int i=0; i<=n; i++)	f[i] = i;
		sort(p, p+m, cmp);
		for(int i=0; i<m; i++) {
			int fx = find(p[i].x);
			int fy = find(p[i].y);
			if(fx != fy) {
				f[fx] = fy;
				
			}
		}
	}
	
	return 0;
} 
