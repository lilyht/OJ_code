#include <iostream>
#include <string.h>
#include <cmath>
#include <iomanip>
using namespace std;
const int MAXN = 105;
const int INF = 0x7fffff;
//prim
//2020-08-23 11:30:48	Accepted	1875	156MS	1836K	1358 B	G++
//稠密图 
struct node{
	double x;
	double y;
}a[MAXN];

double mp[MAXN][MAXN];
bool vis[MAXN];
double d[MAXN];

double cal(node a, node b) {
	double x = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(x);
}

int main() {
	int t, c;
	cin>>t;
	while(t--) {
		cin>>c;
		for(int i=0; i<c; i++)
			cin>>a[i].x>>a[i].y;
		//DEAL
		for(int i=0; i<c; i++) {
			vis[i] = 0;
			for(int j=0; j<c; j++) {
				mp[i][j] = INF;
			}
		}
		for(int i=0; i<c; i++) {
			for(int j=0; j<i; j++) {
				double dis = cal(a[i], a[j]);
				if(dis >= 10 && dis <= 1000)
					mp[i][j] = mp[j][i] = dis;
			}
		}
		for(int i=0; i<c; i++)
			d[i] = mp[0][i];
		//加入初始节点0
		double ans = 0;
		vis[0] = 1;
		d[0] = 0;
		int x = 0;
		int flag = 0;
		for(int i=1; i<c; i++) {
			double temp = INF;
			for(int j=0; j<c; j++) {
		 		if(!vis[j] && d[j] < temp) {
		 			temp = d[j];
		 			x = j;
				 }
			}
			if(temp == INF) {
				flag = 1;
			}
			vis[x] = 1;
			ans += temp;
			d[x] = temp;
			for(int j=0; j<c; j++) {
				if(!vis[j] && d[j] > mp[x][j]) {
					d[j] = min(d[j], mp[x][j]);
				}
			}
		}
		cout<<fixed<<setprecision(1);
		if(flag == 1)	cout<<"oh!"<<endl;
		else	cout<<ans*100<<endl;
	}
	return 0;
}
