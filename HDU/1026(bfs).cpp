#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
//参考 https://blog.csdn.net/liangzhaoyang1/article/details/51525323 
int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};
int map[105][105], vis[105][105];
int n, m;

struct node{
	int rec[1000][5];
	int x, y;
	int step;
};

void bfs(int n, int m) {
	queue<node> Q;
	node st;
	st.x = 0;	st.y = 0;	st.step = 0;
	Q.push(st);
	while(!Q.empty()) {
		node cur = Q.front();
		Q.pop();
		if(cur.x == n-1 && cur.y == m-1) {
			cout<<"It takes "<<cur.step<<" seconds to reach the target position, let me show you the way."<<endl;
			for(int i=0; i<cur.step; i++) {
				cout<<i+1<<"s:";
				int tp = cur.rec[i][0];
				if(tp == 2) {
					cout<<"FIGHT AT ("<<cur.rec[i][2]<<","<<cur.rec[i][1]<<")"<<endl;
				}
				else if(tp == 4) {
					cout<<"("<<cur.rec[i][2]<<","<<cur.rec[i][1]<<")->("<<cur.rec[i][4]<<","<<cur.rec[i][3]<<")"<<endl;
				}
			}
			return;
		}
		else if(map[cur.x][cur.y] > 0) {  //停留打怪 
			node fight;
			fight.x = cur.x;	fight.y = cur.y;
			for(int i=0; i<cur.step; i++) {
				for(int j=0; j<5; j++)	
					fight.rec[i][j] = cur.rec[i][j];
			}
			//把作战的两个数字传入
			fight.rec[cur.step][0] = 2;
			fight.rec[cur.step][1] = cur.x;
			fight.rec[cur.step][2] = cur.y;
			fight.step = cur.step + 1;  //步数加一
			map[cur.y][cur.x] = map[cur.y][cur.x] - 1;  //地图上的点减小一，怪的血下降1滴  //是不是反了呀？？？ 
			Q.push(fight);
		}
		else {
			for(int i=0; i<4; i++) {
				int x_ = cur.x + dx[i];
				int y_ = cur.y + dy[i];
				if(x_ < n && x_ >=0 && y_ < m && y_ >=0 && map[x_][y_] != -1 && !vis[x_][y_]) {
					vis[x_][y_] = 1;
					node s2;
					s2.x = x_;	s2.y = y_;
					for(int i=0; i<cur.step; i++) {
						for(int j=0; j<5; j++)	
							s2.rec[i][j] = cur.rec[i][j];
					}
					s2.rec[cur.step][0] = 4;
					s2.rec[cur.step][1] = cur.x;
					s2.rec[cur.step][2] = cur.y;
					s2.rec[cur.step][3] = x_;
					s2.rec[cur.step][4] = y_;
					s2.step = cur.step + 1; //步数加一
					Q.push(s2);
				}
				
			}
		} 
	}
	cout<<"God please help our poor hero."<<endl;
	return;
}

int main() {
	while(cin>>n>>m) {
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		char ch;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>ch;
				if(ch == '.')
					map[i][j] = 0;
				else if(ch == 'X')
					map[i][j] = -1;
				else
					map[i][j] = ch - '0';
			}
		}
		bfs(n, m);
		cout<<"FINISH"<<endl;
	}
	return 0;
} 
