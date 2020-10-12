#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
//2020-08-23 15:04:18	Accepted	1879	405MS	1448K	820 B	G++
const int MAXN = 105;

struct edge{
	int x;
	int y;
	int cost;
}p[MAXN*MAXN>>1];  //注意：之前因为这里错写成MAXN而TLE三次 
int f[MAXN];

bool cmp(edge u, edge v) {
	return u.cost < v.cost;
}

int find(int x) {
	if(x == f[x])	return x;
	return f[x] = find(f[x]);
}

int main() {
	int n, a, b, c, s;
	while(~scanf("%d", &n) && n) {
		int m = n*(n-1) >> 1;
		for(int i=0; i<m; i++) {
			scanf("%d%d%d%d", &a, &b, &c, &s);
			p[i].x = a; p[i].y = b;
			if(s == 1)
				p[i].cost = 0;
			else
				p[i].cost = c;
				
		}
		for(int i=0; i<=n; i++)	f[i] = i;
		sort(p, p+m, cmp);
		//遍历边
		int ans = 0;
		for(int i=0; i<m; i++) {
			int fx = find(p[i].x);
			int fy = find(p[i].y);
			if(fx != fy) {
				f[fx] = fy;
				ans += p[i].cost; 
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
