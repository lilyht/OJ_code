#include <iostream>
#include <bits/stdc++.h>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
#define Pair pair<int,int>
const int MOD = 1E9+7;
const int N = 50000+5;
const int dx[] = {1,-1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;


struct Node {
	int to,dis;
	Node() {}
	Node(int to,int dis):to(to),dis(dis) {}
};
vector<Node> G[N];
int in[N];
int dis[N];
int n,m;

void topSort() {
	stack<int > S;
	for(int i=1; i<=n; i++)
		if(!in[i])
			S.push(i);

	while(!S.empty()) {
		int x=S.top();
		S.pop();
		for(int j=0; j<G[x].size(); j++) {
			int y = G[x][j].to;
			dis[y] = max(dis[y], dis[x] + G[x][j].dis);  //here: 在拓扑排序的基础上加上这两处就可以啦 
			in[y]--;
			if(!in[y])
				S.push(y);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		memset(in, 0, sizeof(in));
		memset(dis, 0, sizeof(dis));
		for(int i=0; i<=n; i++)
			G[i].clear();

		for(int i=1; i<=m; i++) {
			int x, y, dis;
			scanf("%d%d%d", &x, &y, &dis);
			Node temp;
			temp.to = y;
			temp.dis = dis;
			in[y]++;
			G[x].push_back(temp);
		}
		topSort();

		int res = -INF;
		for(int i=1; i<=n; i++)
			res = max(res, dis[i]);  //here 在拓扑排序的基础上加上这两处就可以啦 
		printf("%d\n",res);
	}
	return 0;
}
/**
1
9 11
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
8 9 4
7 9 2
**/
