#include <iostream>
#include <algorithm>
using namespace std;

// kruskal算法
//对于稀疏图最好使用这个算法 

int f[30];
int n, k, cost;
char a, b;

struct node{
	char e1, e2;
	int dis;
}p[10000];

int find(int x) {
//	cout<<x<<endl;
	if(f[x] == x) 	return x;
	return find(f[x]);
} 

bool cmp(node x, node y) {
	return x.dis < y.dis;
}

int main() {
	while(cin>>n && n) {
		int num = 0; 
		//初始化并查集
		for(int i=0; i<=27; i++)
			f[i] = i;
		
		for(int l=1; l<n; l++) {
			cin>>a>>k;
			for(int i=0; i<k; i++) {
				cin>>b;
				p[num].e2 = b - 'A' + 1;
				cin>>p[num].dis;
				p[num].e1 = a - 'A' + 1;
				num++;  //道路总数 
			}
		}
		
		int ans = 0;
		//从小到大排序
		sort(p, p+num, cmp); 
		//遍历所有的道路 
		for(int i=0; i<num; i++) {
			int fx = find(p[i].e1);
			int fy = find(p[i].e2);
			//判断是否连通 
			if(fx != fy) {
				//不连通 
				ans += p[i].dis;
				f[fx] = fy; 
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
