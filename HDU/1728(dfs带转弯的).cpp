#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
//2020-08-27 21:40:57	Accepted	1728	78MS	1504K	1632 B	G++
const int MAXN = 105;

int k, m, n, x1, y1, x2, y2;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char mp[MAXN][MAXN];
int shortnum[MAXN][MAXN];

struct node{
	int x, y, num;
	int di, dj;
	friend bool operator < (node a, node b) {
		return a.num > b.num;
	} 
};
priority_queue<node> q;

int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>m>>n;
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				cin>>mp[j][i];
			}
		}
		cin>>k>>x1>>y1>>x2>>y2;
		if(x1<=0 || y1<=0 || x2<=0 || y2<=0 || k<0) {
			cout<<"no"<<endl;
			continue;
		}
		if(mp[x1][y1] == '*' || mp[x2][y2] == '*') {
			cout<<"no"<<endl;
			continue;
		}
		//init 
		for(int i=0; i<=n; i++)
			for(int j=0; j<=m; j++)
				shortnum[i][j] = 99999999; 
		while(!q.empty())	q.pop();
		node n1;
		n1.x = x1, n1.y = y1, n1.num = -1;
		n1.di = 0, n1.dj = 0;
		q.push(n1);
		bool flag = 0;
		node u, v;
		while(!q.empty()) {
			u = q.top();
			q.pop();
			if(u.x == x2 && u.y == y2) {
				if(u.num <= k)
					cout<<"yes"<<endl;
				else
					cout<<"no"<<endl;
				flag = 1;
				break;
			}
			for(int i=0; i<4; i++) {
				v.x = u.x + dx[i];
				v.y = u.y + dy[i];
				v.di = dx[i];
				v.dj = dy[i];
				v.num = u.num;
				if(v.x>0 && v.x<=n && v.y>0 && v.y<=m && mp[v.x][v.y] == '.') {
					//判断方向, 为 num 字段赋值
					if(u.di != v.di || u.dj != v.dj) {
						v.num++;
					}
					if(v.num <= shortnum[v.x][v.y]) {
						//最少转弯次数，更新并放入队列
						q.push(v);
						shortnum[v.x][v.y] = v.num;
					}
				}
			}
		}
		if(flag == 0)
			cout<<"no"<<endl;
	}
	return 0;
}
