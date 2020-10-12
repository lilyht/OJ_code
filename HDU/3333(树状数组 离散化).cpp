#include <cstdio>
#include <algorithm>
#include <cstring>
//2020-08-18 15:04:06	Accepted	3333	452MS	4032K	1752 B	G++ 
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 7;

struct Node {
	int x, y, id;
}q[maxn];

ll a[maxn], b[maxn], c[maxn], ans[maxn];
int pre[maxn];
int n;

int cmp(Node a, Node b) {
	return a.y < b.y;
}

int lowbit(int x) {
	return x & -x;
}

void add(int x, ll v) {
	while(x < maxn) {
		c[x] += v;
		x += lowbit(x);
	}
}

ll sum(int x) {
	ll res = 0;
	while(x) {
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}

int Bin(ll x) {
	return lower_bound(b+1, b+1+n, x) - b;
	//lower_bound: 从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字
	//找到返回该数字的地址，不存在则返回end
	//最后 -b 找到数字在数组中的下标
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		//init
		for(int i = 1; i <= n; i++) {
			c[i] = 0;
			pre[i] = 0;
		}
		
		for(int i = 1; i <= n; i++) {
			scanf("%lld",&a[i]);
			b[i] = a[i];
		}
		sort(b+1, b+1+n);  //对输入序列排序 
		int m;
		scanf("%d", &m);
		for(int i=1; i<=m; i++) {
			scanf("%d%d", &q[i].x, &q[i].y);  //查询的左右区间 
			q[i].id = i;
		}
		sort(q+1, q+1+m, cmp);  //对查询右区间升序排序 
		int j = 1;
		//最开始从位置1开始，从当前位置到他的右区间内，如果当前数字未被访问过，就把这个数字加入 。同时做出答案并存在ans数组 
		for(int i = 1; i <= n; i++) {
			int t = Bin(a[i]);  //从b数组中二分查找a[i]元素的下标t 
			if(pre[t]) {
				add(pre[t], -a[i]);  //重复元素，需要从涉及到的区间中全部删除，即-a[i]，这样保证询问区间内每个数字只被加一次
			}
			add(i, a[i]);
			pre[t] = i;

			for(; j <= m; j++) {
				if(q[j].y != i)  //还不能计算出结果
					break;
				ans[q[j].id] = sum(q[j].y) - sum(q[j].x - 1);
			}
		}

		for(int i=1; i<=m; i++) {
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}
