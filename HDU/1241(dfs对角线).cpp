#include <iostream>
#include <string.h>
using namespace std;
//2020-08-27 22:31:38	Accepted	1241	31MS	1536K	793 B	G++
const int MAXN = 105;
int n, m;
char mp[MAXN][MAXN];
int vis[MAXN][MAXN];
//算对角线——八个方位 
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
 
void dfs(int x, int y) {
	for(int i=0; i<8; i++) {  //八个方向 
		int x_ = x + dx[i];
		int y_ = y + dy[i];
		if(x_>=0 && x_<m && y_>=0 && y_<n && mp[x_][y_] == '@') { 
			mp[x_][y_] = '*';  //把属于这一个大油田中的每一个都标记成* 
			dfs(x_, y_);
		}
	}
	return;
}

int main() {
	while(cin>>m>>n && m+n) {
//		cout<<m<<" "<<n<<endl;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cin>>mp[i][j];
			}
		}
		int cnt = 0;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(mp[i][j] == '@') {
					mp[i][j] = '*';
					dfs(i, j);
					cnt++;
				}
					
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
