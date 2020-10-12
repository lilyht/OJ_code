#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
//2020-08-15 21:15:34	Accepted	1698	655MS	3436K	1246 B	G++ 


int T, n, l, r, v, q, sum[maxn*4], cur[maxn*4], kase=0;

void push_up(int o) {
	sum[o] = sum[o<<1] + sum[o<<1|1];
}

void pushdown(int o, int l, int r) {
	if(cur[o]) {  // != 0，就说明需要懒更新 
		int m = (l + r) >> 1;
		cur[o<<1] = cur[o<<1|1] = cur[o];  //左右孩子都标记为懒更新 
		sum[o<<1] = (m - l + 1) * cur[o];
		sum[o<<1|1] = (r - m) * cur[o];
		cur[o] = 0;  //传递完成，标记改回 0 
	}
}

void build(int l, int r, int o) {
	int m = (l + r) >> 1;
	cur[o] = 0;
	if(l == r) {
		sum[o] = 1;
		return ;
	}
	build(l, m, o<<1);
	build(m+1, r, o<<1|1);  //  2n+1
	push_up(o);
}

void update(int L, int R, int c, int l, int r, int o) {
	int m = (l + r) >> 1;
	if(L <= l && r <= R) {
		cur[o] = c;
		sum[o] = c * (r - l + 1);
		return ;
	}
	pushdown(o, l, r);
	if(L <= m) update(L, R, c, l, m, o<<1);
	if(m < R) update(L, R, c, m+1, r, o<<1|1);
	push_up(o);
}

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&q);
		build(1, n, 1);
		while(q--) {
			scanf("%d%d%d", &l, &r, &v);
			update(l, r, v, 1, n, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", ++kase , sum[1]);
	}
	return 0;
}
