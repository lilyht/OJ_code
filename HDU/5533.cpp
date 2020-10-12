#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 110;
//2020-09-18 15:59:44	Accepted	5533	46MS	1464K	853 B	G++
struct node{
	int x, y;
}a[MAXN];
int v[MAXN*MAXN];

int dis(int dl, int ly) {
	return (a[dl].x - a[ly].x)*(a[dl].x - a[ly].x) + (a[dl].y - a[ly].y)*(a[dl].y - a[ly].y);
}

bool cmp(node p, node q) {
	if(p.x != q.x)
		return p.x < q.x;
	else
		return p.y < q.y;
}

int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y;
		}
		if(n != 4) {
			cout<<"NO"<<endl;
			continue;
		}
		sort(a+1, a+5, cmp);
		memset(v, 0, sizeof(v));
		int cnt = 0;
		for(int i=1; i<=4; i++) {
			for(int j=1; j<i; j++) {
				v[cnt++] = dis(i, j);
//				cout<<v[cnt-1]<<endl;
			}
		}
		
		if(v[0]==v[1] && v[1]==v[4] && v[4]==v[5] && v[2]==v[3]) {
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
