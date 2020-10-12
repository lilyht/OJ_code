#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;
//HDU	Accepted	2647	31MS	1920K	1138 B	G++ 
int n, m, a, b;
int indegree[10005];
int cost[10005];
vector<int> G[10005];
queue<int> Q; 

int main() {
	while(~scanf("%d%d", &n, &m)) {
		//init
		for(int i=0; i<10005; i++) {
			G[i].clear();
			indegree[i] = 0;
			cost[i] = 0;
		}
		//input & store
		for(int i=0; i<m; i++) {
			scanf("%d%d", &a, &b);
			//a要比b多，则 b-> a，初始入度为0的点是888 
			G[b].push_back(a);
			indegree[a]++;
		}
		//清空队列
		while(!Q.empty())	Q.pop();
		//统计入度为0的节点
		for(int i=1; i<=n; i++) {
			if(indegree[i] == 0) {
				Q.push(i);
				cost[i] = 0;
			}
		}
		int cnt = 0;
		while(!Q.empty()) {
			int cur = Q.front();
			cnt++;
			Q.pop();
			//与cur相邻的节点入度减1
			for(int i=0; i<G[cur].size(); i++) {
				indegree[G[cur][i]]--;
				if(indegree[G[cur][i]] == 0) {
					Q.push(G[cur][i]);
					cost[G[cur][i]] = cost[cur] + 1;
				}
			} 
		}
		if(cnt != n) {  //有环 
			printf("-1\n");
			continue;
		}
		int base = 888 * n;
		int layer = 0;
		for(int i=1; i<=n; i++)
			layer += cost[i];
		printf("%d\n", base+layer);
	}
	
	return 0;
}
