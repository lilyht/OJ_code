#include <iostream>
#include <string.h>
using namespace std;
//prim
//不容易啊，前前后后交了5遍才过 
//2020-08-23 09:36:18	Accepted	1863	0MS	1440K	1114 B	G++
const int inf = 0x7fffffff;
int mp[105][105];
int vis[105];
int dis[105];

int main() {
	int n, m, a, b, c;
	while(cin>>n>>m && n != 0) {
		//init
		for(int i=0; i<=m; i++) {
			vis[i] = 0;
			dis[i] = inf;
			for(int j=0; j<=m; j++) {
				mp[i][j] = inf;
			}
		}
		//input
		for(int i=1; i<=n; i++) {
//			mp[i][i] = 0;
			cin>>a>>b>>c;
			mp[a][b] = mp[b][a] = min(c, mp[a][b]);
		}
		//加入初始节点
		vis[1] = 1;
		dis[1] = 0;  // 
		int ans = 0;
		//init
		for(int i=1; i<=m; i++)
			dis[i] = mp[1][i];  //初始化为1到节点的距离
		
		//遍历点
		int x;
		bool flag = 0;
		for(int i=1; i<m; i++) {
			int temp = inf;
			for(int j=1; j<=m; j++) {
				if(!vis[j] && dis[j] < temp) {
					temp = dis[j];
					x = j;
				}
			}
			if(temp == inf) {  //这部分一开始没写，就WA了 
				flag = 1;  //代表结束
				break;
			}
            	
			vis[x] = 1;
			ans += temp;
			//update
			for(int j=1; j<=m; j++) {
				if(!vis[j] && dis[j] > mp[x][j]) {
					dis[j] = min(dis[j], mp[x][j]);
				}
			}
		}
		if(flag != 1)  //判断条件也要注意 
			cout<<ans<<endl;
		else
			cout<<"?"<<endl;
	}
	
	return 0;
}
