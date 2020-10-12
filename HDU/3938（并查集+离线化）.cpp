#include <iostream>
#include <algorithm> 
#define INF 2000000000
#define MAXN 10005
using namespace std;
//2020-09-15 18:16:25	Accepted	3938	140MS	2220K	1685 B	G++
//��ĿҪ������ж��ٸ���� 
//�ο���https://www.bbsmax.com/A/LPdo1mkyJ3/
//�ο���https://codeleading.com/article/39491293926/ 
int n, m, q;
int father[MAXN],  num[MAXN];
long long out[MAXN];

struct node {  //�� 
	int u, v, w;
	bool operator < (const node &a) const {
		return w < a.w;
	}
}edge[MAXN * 10];

struct wen {  //���� 
	int l, id;
	bool operator < (const wen &a) const {
		return l < a.l;
	}
}p[MAXN];

void init() {
	for(int i = 1; i <= n; i++) {
		father[i] = i;
		num[i] = 1;
	}
}

int find(int x) {
	if(father[x] == x) return x;
	int t = find(father[x]);
	father[x] = t;
	return t;
}

int join(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if(fx == fy) return 0;
	int t = num[fx] * num[fy];  //���ܵ���� 
	num[fx] += num[fy];
	num[fy] = 0;
	father[fy] = fx;
	return t;
}

int main() {
	while(scanf("%d%d%d", &n, &m, &q) != EOF) {
		init();
		for(int i = 1; i <= m; i++)
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		sort(edge + 1, edge + m + 1);  //�߳���С�������� 
//		for(int i=1; i<=m+1; i++)
//			cout<<edge[i].w<<" ";
		for(int i = 1; i <= q; i++) {
			scanf("%d", &p[i].l);
			p[i].id = i;
		}
		sort(p + 1, p + q + 1);  //���ⰴ��l��С�������� 
//		for(int i=1; i<=m+1; i++)
//			cout<<p[i].l<<" ";
		int pos = 1;
		long long ans = 0;
		for(int i = 1; i <= q; i++) {
			//��ÿ��L��������С�ı�Ȩ�ı߶�����һ�𣬼������������� 
			while(pos <= m && edge[pos].w <= p[i].l) {
				ans += join(edge[pos].u, edge[pos].v);
				pos ++;
			}
			out[p[i].id] = ans;
		}
		for(int i = 1; i <= q; i++)
			printf("%I64d\n", out[i]);
	}
	return 0;
}
