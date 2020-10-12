#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
//HDU	Accepted	1285	15MS	1440K	1051 B	G++
int n, m, a, b;
int indegree[505];
vector<int> G[505];  //邻接表 
priority_queue<int, vector<int>, greater<int> > Q;  //因为输出顺序从小到大，所以使用优先队列 

int main() {
	while(~scanf("%d%d", &n, &m)) {
		//init
		memset(indegree, 0, sizeof(indegree));
		for(int i=0; i<505; i++)
			G[i].clear();
		for(int i=0; i<m; i++) {
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			indegree[b]++;
		}
		//C++中的queue自身是不支持clear操作，因此手动清空 
		while(!Q.empty())	Q.pop();
		//统计所有节点的入度，把入度为0的加入队列Q
		for(int i=1; i<=n; i++)
			if(indegree[i] == 0)
				Q.push(i);
		bool flag = 1;
		while(!Q.empty()) {
			int cur = Q.top();
			if(flag) {
				printf("%d", cur);
				flag = 0;
			}
			else
				printf(" %d", cur);
			Q.pop();
			//把与节点cur相邻的节点入度减1，一共 G[cur].size()个 
			for(int i=0; i<G[cur].size(); i++) {
				indegree[G[cur][i]]--;
				if(indegree[G[cur][i]] == 0)
					Q.push(G[cur][i]);
			}
		}
		printf("\n");
	}

	return 0;
}
