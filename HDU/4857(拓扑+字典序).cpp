#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;
#define INF 1e8
#define eps 1e-8
#define LL long long
#define maxn 505
#define mod  1000000007
vector<int> G[30003];
int out[30003];
int n, m, a[30003];

void toposort() {
	priority_queue<int> q;
	int len = n;
	for(int i=1; i<=n; i++)
		if(out[i] == 0)
			q.push(i);
	while(!q.empty()) {
		int tmp = q.top();
		a[len--] = tmp;
		q.pop();
		for(int i=0; i<G[tmp].size(); i++) {
			out[G[tmp][i]]--;
			if(out[G[tmp][i]] == 0)
				q.push(G[tmp][i]);
		}
	}
	for(int i=1; i<n; i++)
		printf("%d ", a[i]);
	printf("%d\n", a[n]);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		int a, b;
		for(int i=1; i<=n; i++)
			out[i] = 0, G[i].clear();
		while(m--) {
			scanf("%d%d", &a, &b);
			G[b].push_back(a);
			out[a]++;
		}
		toposort();
	}
	return 0;
}
/*
1
5 10
3 5
1 4
2 5
1 2
3 4
1 4
2 3
1 5
3 5
1 2
*/
