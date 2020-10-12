#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

// 2020-08-08 12:24:32	Accepted	4786	499MS	2960K	1608 B	G++ 

int f[100005];
int fib[28];

struct edge{
	int x, y;
	int w;  //0表示黑色，1表示白色 
}p[100005]; 

bool cmp1(edge a, edge b) {
	return a.w > b.w;
}

bool cmp2(edge a, edge b) {
	return a.w < b.w;
}

int find(int x) {  //找祖宗节点 
	if(f[x] == x)	return x;
	return f[x] = find(f[x]);  //加上 f[x] = 之后不超时了 
} 

void fibnum() {
	fib[1] = 1, fib[2] = 2;
	for(int i=3; i<28; i++)
		fib[i] = fib[i-2] + fib[i-1];
//	cout<<fib[4]<<endl;
}
 
int main() {
	int t, n, m;
	int kse = 1;
	fibnum();
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i=0; i<m; i++) {
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].w);
		}
		printf("Case #%d: ", kse++);
		
		/*找最小生成树*/ 
		for(int i=0; i<= n; i++)	f[i] = i;
		//sort
		sort(p, p+m, cmp2); 
		//检查是否连通
		int cnt = 0; 
		int minans = 0;
		for(int i=0; i<m; i++) {  //这里之前下标写错了 
			int fx = find(p[i].x);
			int fy = find(p[i].y);
			if(fx != fy) {
				f[fx] = fy;
				cnt++;
				minans += p[i].w;
			}
		}
		if(cnt != n-1) {
			//不连通
			printf("No\n");
			continue;
		}
		
		/*找最大生成树了 */
		for(int i=0; i<=n; i++)	f[i] = i;
		sort(p, p+m, cmp1);
		int maxans = 0;
		for(int i=0; i<m; i++) {
			int fx = find(p[i].x);
			int fy = find(p[i].y);
			if(fx != fy) {
				f[fx] = fy;
				maxans += p[i].w;
			}
		}
		//找fib 
		int flag = 0;
		for(int i=1; i<28; i++) {
			if(fib[i] >= minans && fib[i] <= maxans)
				flag = 1;
		}
		if(flag == 1)
			printf("Yes\n");
		else
			printf("No\n");
//		cout<<"minans: "<<minans<<"  maxans: "<<maxans<<endl;
	}
	
	return 0;
}
