#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
using namespace std;
const int MAXN = 55;
const int INF = 999999999;
bool vis[MAXN];
double d[MAXN];
double dis[MAXN][MAXN];
int n;
//2020-09-15 13:58:37	Accepted	4463	0MS	1724K	1427 B	G++
struct node {
	int x;
	int y;
}a[MAXN];

double getDis(int u, int v) {
	return sqrt((a[u].x - a[v].x)*(a[u].x - a[v].x) + (a[u].y - a[v].y)*(a[u].y - a[v].y));
}

double prim() {
	double ans = 0.0;
	vis[1] = 1;
	d[1] = 0;
	for(int i=1; i<=n; i++)
		d[i] = dis[1][i];
	int x;
	double tmp = INF;
	for(int i=1; i<n; i++) {  //遍历n-1个点 ATTENTIOM!!!
		tmp = INF;  //加上 ATTENTIOM!!!
		for(int j=1; j<=n; j++) {
			if(!vis[j] && d[j] < tmp) {
				x = j;
				tmp = d[j];
			}
		}
		vis[x] = 1;
		ans += tmp;
		for(int j=1; j<=n; j++) {
			if(!vis[j] && d[j] > dis[x][j]) {
				d[j] = min(d[j], dis[x][j]);
			}
		}
	}
	return ans;
}

int main() {
	int p, q, qx, qy;
	while(cin>>n && n) {
		cin>>p>>q;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y;
		}
		//init
		for(int i=0; i<55; i++)
			for(int j=0; j<55; j++)
				dis[i][j] = 999999999;
		memset(vis, 0, sizeof(vis));
		//calculate the distance
		//稠密图，用prim好 
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				double disnum = getDis(i, j);
				dis[i][j] = dis[j][i] = disnum;
			}
		}
		dis[p][q] = 0, dis[q][p] = 0;  //ATTENTIOM!!!
		
		double ans = prim();
//		cout<<"(p, q): "<<getDis(p, q)<<endl;
		ans += getDis(p, q);
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
	return 0;
}
