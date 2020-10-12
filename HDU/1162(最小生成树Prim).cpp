#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define INF 0x7fffffff
double x, y, cost;
double mp[105][105];
double d[105];
int vis[105];

struct point{
	double x, y;
}p[105];

double dis(point a, point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
	int n;
	while(cin>>n) {
		//init
		cout<<fixed<<setprecision(2); 
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=n; j++) {
				mp[i][j] = INF;
			}
			d[i] = INF;
			vis[i] = 0;
		}
		
		for(int i=1; i<=n; i++)
			cin>>p[i].x>>p[i].y;
			
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				cost = dis(p[i], p[j]);
	//			cout<<cost<<endl;
				mp[i][j] = mp[j][i] = cost;
			}
		}
		vis[1] = 1;
		d[1] = 0;
		double ans = 0.0;
		for(int i=1; i<=n; i++)	d[i] = mp[i][1];
		
		int x;
		for(int i=1; i<n; i++) {
			int temp = INF;
			for(int j=0; j<=n; j++) {
				if(!vis[j] && d[j] < temp)	temp = d[x=j];
			}
			vis[x] = 1;
			ans += d[x];
			
			for(int j=1; j<=n; j++) {
				if(!vis[j])
					d[j] = min(d[j], mp[x][j]);
			}
		}
		 
		cout<<ans<<endl;
	}
	
	return 0;
}
