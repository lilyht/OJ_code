#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
//2020-08-13 10:27:50	Accepted	1242	93MS	1600K	1380 B	G++
int n, m, ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char mp[204][204];
int vis[204][204];

struct node{
	int x, y;
	int cost;
	friend bool operator < (node a, node b) {
		return a.cost > b.cost;
	}
};

int bfs(int sx, int sy, int sc) {
//	queue<node> q;
	priority_queue<node> q;
	while(!q.empty())	q.pop();
	node st;
	st.x = sx; st.y = sy; st.cost = sc;
	q.push(st);
	while(!q.empty()) {
		node tmp = q.top();
		q.pop();
		if(mp[tmp.x][tmp.y] == 'r') {
			ans = tmp.cost;
			return 1;
		}
		for(int i=0; i<4; i++) {
			int x_ = tmp.x + dx[i];
			int y_ = tmp.y + dy[i];
			if(x_>=0 && x_<n && y_>=0 && y_<m && mp[x_][y_] != '#' && !vis[x_][y_]) {
				int step = tmp.cost + 1;
				vis[x_][y_] = 1;
				if(mp[x_][y_] == 'x')
					step += 1;
				node nxt;
				nxt.x = x_;	nxt.y = y_;	nxt.cost = step;
				q.push(nxt);
			}
		}
	}
	return -1;
}

int main() {
	while(cin>>n>>m) {
		int sx = 0;
		int sy = 0;
		ans = 0;
		memset(mp, 0, sizeof(mp));
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>mp[i][j];
				if(mp[i][j] == 'a') {
					sx = i;
					sy = j;
				}
			}
		}
		vis[sx][sy] = 1;
		int flag = bfs(sx, sy, 0);
		if(flag == 1)	cout<<ans<<endl;
		else	cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
	}
	return 0;
}
