#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
//https://blog.csdn.net/moon_sky1999/article/details/81274345
//2020-08-18 17:35:51	Accepted	2795	3322MS	2948K	975B	G++
const int maxn = 200005;
int h, w, n, m;
int c[maxn], a[maxn];

int lb(int x) {
	return x & -x;
}

int query(int x) {
	int res = 0;
	for (; x; x -= lb(x))
		res = max(res, c[x]);
	return res;
}

void update(int x) {
	for (; x <= n; x += lb(x)) {
		c[x] = a[x];
		int t = x - lb(x);  //y取值范围在（x - lb(x)， x-1）之间 ，即重新更新x覆盖范围 
		for (int y = x - 1; y && y-lb(y) >= t; y-=lb(y))
			c[x] = max(c[x], c[y]);
	}
}

int main() {
	while (~scanf("%d%d%d", &h, &w, &m)) {
		n = min(m, h);
		for (int i = 1; i <= n; ++i) {
			c[i] = w;
			a[i] = w;
		}
		int x;
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &x);
			int l = 1, r = n;
			while (l < r) {  //二分 
				int mid = (l + r) >> 1;
				if (query(mid) >= x)
					r = mid;
				else
					l = mid + 1;
			}
			if (a[l] < x)
				printf("-1\n");
			else {
				a[l] -= x;
				update(l);
				printf("%d\n", l);
			}
		}
	}
	return 0;
}
