#include <iostream>
#include <string.h>
using namespace std;
#define INF 0x7fffffff

int mp[30][30];
int d[30];
int vis[30];
char a, b;

int main() {
	int n, k, cost;
	while(cin>>n && n) {
		//init
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<=n; i++)	d[i] = INF;
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
				mp[i][j] = INF;
		//cin
		for(int i=1; i<n; i++) {
			cin>>a>>k;
			for(int j=0; j<k; j++) {
				cin>>b>>cost;
				mp[a-'A'+1][b-'A'+1] = mp[b-'A'+1][a-'A'+1] = cost;
			}
		}
		//把第一个节点加进去
		vis[1] = 1;
		d[1] = 0;
		int ans = 0;
		
		for(int i=1; i<=n; i++)  //忘了写!!!
			d[i] = mp[i][1];
		
		//遍历点 
		int x;
		for(int i=1; i<n; i++) {
			int temp = INF;
			for(int j=1; j<=n; j++) {
				if(!vis[j] && d[j] < temp) {
					temp = d[j];
					x = j;
				}
			}
			vis[x] = 1;
			ans += temp;
			for(int j=1; j<=n; j++) {
				if(!vis[j] && d[j] > mp[x][j])
					d[j] = min(d[j], mp[x][j]);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
