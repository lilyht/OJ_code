#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 55;
//2020-09-18 15:26:36	Accepted	5538	93MS	1412K	597 B	G++
int mp[MAXN][MAXN]; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
	int t, n, m;
	cin>>t;
	while(t--) {
		memset(mp, 0, sizeof(mp));
		int ans = 0;
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>mp[i][j];
				if(mp[i][j])
					ans++;  //房顶 
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				ans += 4*mp[i][j];
				for(int k=0; k<4; k++) {
					ans -= min(mp[i][j], mp[i-dx[k]][j-dy[k]]);  //减去重复的 
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
