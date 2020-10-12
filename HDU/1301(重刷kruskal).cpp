#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define inf 999999999;
//2020-09-07 17:44:19	Accepted	1301	0MS	1420K	839 B	G++
int f[30];
char a, b;

struct node {
	int x, y;
	int dis;
}p[1000];

bool cmp(node u, node v) {
	return u.dis < v.dis;
}

int find(int x) {
	if(f[x] == x)	return x;
	return find(f[x]);
}

int main() {
	int n, k, cost;
	while(cin>>n && n) {
		//init
		for(int i=0; i<=n; i++)	f[i] = i;
		//cin
		int cnt = 0;
		for(int i=1; i<n; i++) {
			cin>>a>>k;
			for(int j=0; j<k; j++) {
				cin>>b>>cost;
				p[cnt].x = a - 'A' + 1;
				p[cnt].y = b - 'A' + 1;
				p[cnt].dis = cost;
				cnt++;
			}
		}
		sort(p, p+cnt, cmp);
		int ans = 0;
		for(int i=0; i<cnt; i++) {
			//看是否在一个集合
			int fx = find(p[i].x);
			int fy = find(p[i].y);
			if(fx != fy) {
				f[fx] = fy;
				ans += p[i].dis;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
