#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
//2020-08-28 21:51:45	Accepted	1429	265MS	4160K	1642 B	G++
 
const int MAXN = 24;
int ans = 0;
int sx, sy, ex, ey, n, m, t;
char mp[MAXN][MAXN];
int status[MAXN][MAXN][1030];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct node{
	int x, y, t, key;
};

queue<node> q;

void bfs(int x, int y) {
	bool flag = false;
	node n1, n2; 
	n1.x = x, n1.y = y, n1.t = 0, n1.key = 0;
	status[x][y][0] = 0;
	while(!q.empty())	q.pop();
	q.push(n1);
	while(!q.empty()) {
		if(flag == 1)  //找到结果 
			break;
		n2 = q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			int x_ = n2.x + dx[i];
			int y_ = n2.y + dy[i];
			int ky = n2.key;
			if(x_<0 || x_>=n || y_<0 || y_>=m || mp[x_][y_] == '*')	continue;  //kao！因为边界写少了个等号，一直WA 
			if(mp[x_][y_] >= 'A' && mp[x_][y_] <= 'Z') {
				//大门，位运算看有没有钥匙
				int k = mp[x_][y_] - 'A';
				if(!(ky & (1<<k)))
					continue;
			}
			if(mp[x_][y_] >= 'a' && mp[x_][y_] <= 'z') {
				int k = mp[x_][y_] - 'a';
				ky = n2.key | (1<<k);
			}
			if(status[x_][y_][ky])
				continue;  //该状态访问过
			 status[x_][y_][ky] = 1;  //标记 
			 if(x_ == ex && y_ == ey) {
			 	flag = 1;
			 	ans = min(ans, n2.t + 1);
			 }
			 n1.x = x_, n1.y = y_;
			 n1.t = n2.t + 1;
			 n1.key = ky;
			 q.push(n1);			
		}
	}
	
}

int main() {
	while(cin>>n>>m>>t) {
		memset(status, 0, sizeof(status));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>mp[i][j];
				if(mp[i][j] == '@')
					sx = i, sy = j;
				else if(mp[i][j] == '^')
					ex = i, ey = j;
			}
		}
		ans = 99999999;
		bfs(sx, sy);
		if(ans < t)	cout<<ans<<endl;
		else	cout<<"-1"<<endl;
	}
	return 0;
}
