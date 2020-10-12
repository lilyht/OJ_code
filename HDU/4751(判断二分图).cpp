#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN = 110;
//2020-09-18 10:33:45	Accepted	4751	78MS	1412K	988 B	G++
int n;
bool mp[MAXN][MAXN];
int vis[MAXN];

int bfs(int x) {
	queue<int> q;
	while(!q.empty()) 	q.pop();
	q.push(x);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=1; i<=n; i++) {
			if(i == u || (mp[u][i] && mp[i][u]))	continue;
			if(vis[i] == -1) {
				//δ��ɫ
				vis[i] = vis[u] ^ 1;
				q.push(i);
			}
			else if(vis[u] == vis[i])
				return false;
		}
	}
	return true;
}

int main() {
	while(cin>>n && n) {
		int j;
		memset(mp, 0, sizeof(mp));
		memset(vis, -1, sizeof(vis));
		for(int i=1; i<=n; i++) {
			while(cin>>j && j) {
				mp[i][j] = 1;
			}
		}
		bool flag = false;
		for(int i=1; i<=n; i++) {
			if(vis[i] == -1) { //δȾɫ 
				vis[i] = 0;
				if(!bfs(i)) {
					flag = 1;
					break;
				}
			}
		}
		if(flag)	cout<<"NO"<<endl;
		else	cout<<"YES"<<endl;
//		int ans = -1^1;
//		int ans1 = ans ^ 1;
//		cout<<ans<<" "<<ans1<<endl;
	} 
	return 0;
}
