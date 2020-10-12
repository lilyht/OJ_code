#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int MAXN = 52;
//用了优先队列就超时，改成普通队列就好了...
//2020-08-30 16:03:48	Accepted	1253	1560MS	2148K	1591 B	G++	 
//六个方向 
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int mp[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
int kse, a, b, c, t;
int ans = 99999999;

struct node {
	int x, y, z;  //z代表第几层 
	int t;
//	friend bool operator < (node x, node y) {
//		return x.t > y.t;
//	}
};

//priority_queue<node> q;
queue<node> q;

void bfs(int z, int x, int y) {
	ans = 99999999;
	node n1, n2;
	n1.z = z, n1.x = x, n1.y = y, n1.t = 0;
	while(!q.empty())	q.pop();
	q.push(n1);
	bool flag = false;
	while(!q.empty()) {
//		n2 = q.top();
		n2 = q.front();
		q.pop();
		if(n2.x == b-1 && n2.y == c-1 && n2.z == a-1 && n2.t <= t) {
			flag = 1;
			printf("%d\n", n2.t);
			break;
		}
			
		for(int i=0; i<6; i++) {
			int x_ = n2.x + dx[i];
			int y_ = n2.y + dy[i];
			int z_ = n2.z + dz[i];
			if(x_<0 || x_>=b || y_<0 || y_>=c || z_<0 || z_>=a || mp[z_][x_][y_] == 1)
				continue;
			if(n2.t + 1 <= t && vis[z_][x_][y_] == 0) {
				n1.x = x_, n1.y = y_, n1.z = z_;
				n1.t = n2.t + 1;
				q.push(n1);
				vis[z_][x_][y_] = 1;
			}
		} 
	}
	if(!flag)	printf("-1\n");
} 

int main() {
	scanf("%d", &kse);
	while(kse--) {
		scanf("%d%d%d%d", &a, &b, &c, &t);
		memset(mp, 0, sizeof(mp));
		memset(vis, 0, sizeof(vis));
		for(int k=0; k<a; k++) {  //第k块 
			for(int i=0; i<b; i++) {
				for(int j=0; j<c; j++) {
					scanf("%d", &mp[k][i][j]);
				}
			}
		}
		if(mp[a-1][b-1][c-1] == 1)
			printf("-1\n");
		else
			bfs(0, 0, 0);
	}
	return 0;
} 
