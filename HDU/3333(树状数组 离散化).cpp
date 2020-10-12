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
	//lower_bound: �������beginλ�õ�end-1λ�ö��ֲ��ҵ�һ�����ڻ����num������
	//�ҵ����ظ����ֵĵ�ַ���������򷵻�end
	//��� -b �ҵ������������е��±�
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
		sort(b+1, b+1+n);  //�������������� 
		int m;
		scanf("%d", &m);
		for(int i=1; i<=m; i++) {
			scanf("%d%d", &q[i].x, &q[i].y);  //��ѯ���������� 
			q[i].id = i;
		}
		sort(q+1, q+1+m, cmp);  //�Բ�ѯ�������������� 
		int j = 1;
		//�ʼ��λ��1��ʼ���ӵ�ǰλ�õ������������ڣ������ǰ����δ�����ʹ����Ͱ�������ּ��� ��ͬʱ�����𰸲�����ans���� 
		for(int i = 1; i <= n; i++) {
			int t = Bin(a[i]);  //��b�����ж��ֲ���a[i]Ԫ�ص��±�t 
			if(pre[t]) {
				add(pre[t], -a[i]);  //�ظ�Ԫ�أ���Ҫ���漰����������ȫ��ɾ������-a[i]��������֤ѯ��������ÿ������ֻ����һ��
			}
			add(i, a[i]);
			pre[t] = i;

			for(; j <= m; j++) {
				if(q[j].y != i)  //�����ܼ�������
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
