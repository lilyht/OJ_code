#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector> 
using namespace std;

//HDU 2020-08-08 20:47:43	Accepted	2544	15MS	1484K	1413 B	G++

int n, m, a, b, c;
bool vis[105];
int d[105];

struct E{
	int next;  //相邻节点 
	int w;  //边的权值  
};
vector <E> edge[105];  //邻接表 （vector: 不定长数组） 

int main() {
	while(~scanf("%d%d", &n, &m) && n+m) {
		//初始化邻接表
		for(int i=0; i<=n; i++)	edge[i].clear();
		//处理输入
		for(int i=0; i<m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			E e;
			e.next = b;
			e.w = c;
			edge[a].push_back(e);  // 在edge表的末尾增加一个e元素 
			e.next = a;  //无向图，所以是双向的，push两次 
			edge[b].push_back(e);
		}
		//init
		memset(vis, 0, sizeof(vis));
		for(int i=1; i<=n; i++) {
			d[i] = -1;  //-1表示不可达 
		} 
		//起始节点为1 
		d[1] = 0;
		vis[1] = 1;
		int P = 1;
		for(int i=1; i<n; i++) {
			for(int j=0; j<edge[P].size(); j++) {  //遍历与该新加入集合K中的结点直接相邻的边
				int t = edge[P][j].next;
				int w = edge[P][j].w;
				if(vis[t])
					continue;
				if(d[t] == -1 || d[t] > d[P] + w)  //若该结点尚不可达,或者该结点从新加入的结点经过一条边到达时比以往距离更短
					d[t] = d[P] + w;
			}
			
			int minw = 1000000005;
			for(int j=1; j<=n; j++) {  //遍历所有节点 
				if(!vis[j]) {
					if(d[j] == -1)	continue;  //尚不可达 
					if(d[j] < minw) {
						minw = d[j];
						P = j;
					}
				}
			}
			vis[P] = 1;  //这个新的节点加入集合 
		} 
		printf("%d\n", d[n]);
	}
	
	return 0;
} 
