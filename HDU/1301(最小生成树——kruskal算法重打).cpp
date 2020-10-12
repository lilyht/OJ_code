#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int f[30];
char a, b;

struct node{
	int x, y;  //两端端点 
	int dis;
}p[1000]; 

bool cmp(node s, node t) {
	return s.dis < t.dis;
}

int find(int x) {
	if(f[x] == x)	return x;
	return find(f[x]);
} 

int main() {
	int n, k, cost;
	while(cin>>n && n) {
		int num = 0;
		for(int i=1; i<n; i++) {
			cin>>a>>k;
			for(int i=0; i<k; i++) {
				cin>>b>>cost;
				p[num].x = a-'A'+1;
				p[num].y = b-'A'+1;
				p[num].dis = cost;
				num++;
			}
		}
		//初始化并查集
		for(int i=0; i<=n; i++)	f[i] = i;
		//对边排序（结构体） 
		sort(p, p+num, cmp);
		//遍历边 
		int ans = 0;
		for(int i=0; i<num; i++) {
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
