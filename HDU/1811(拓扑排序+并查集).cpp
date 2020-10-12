#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
//HDU	Accepted	1811	46MS	1944K	1576 B	G++ 
int n, m, cnt;
int f[10005], a[20005], b[20005];
char op[20005];
int indegree[10005];
vector<int> G[10005];

int find(int x) {
	if(x == f[x])	return x;
	return f[x] = find(f[x]);
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		int cnt = n;
		memset(indegree, 0, sizeof(indegree));
		for(int i=0; i<10005; i++){
			G[i].clear();
			f[i] = i;
		}
		
		for(int i=0; i<m; i++) {
			scanf("%d %c %d", &a[i], &op[i], &b[i]);
			if(op[i] == '=') {
				//union
				int fa = find(a[i]);
				int fb = find(b[i]);
				if(fa != fb) {
					f[fa] = fb;
					cnt--;	
				}
			}
		}
		//处理并查集
		for(int i=0; i<m; i++) {
			int fa = find(a[i]);
			int fb = find(b[i]);
			if(op[i] == '>') {
				G[fa].push_back(fb);
				indegree[fb]++;
			}
			if(op[i] == '<') {
				G[fb].push_back(fa);
				indegree[fa]++;
			}
		}
		
		queue<int> Q;
		while(!Q.empty())	Q.pop();
		//统计所有节点的入度，把入度为0的加入队列Q
		for(int i=0; i<n; i++)
			if(indegree[i] == 0 && find(i) == i)  //find(i)==i要加 
				Q.push(i);
		bool flag = 0;
		while(!Q.empty()) {
			if(Q.size() > 1) {
				//第一次如果队列里有多于一个元素，说明有多个入度为0的祖宗节点，也就是信息缺失的情况
				flag = 1; 
			}
			int cur = Q.front();
			Q.pop();
			cnt--;
			for(int i=0; i<G[cur].size(); i++) {
				indegree[G[cur][i]]--;
				if(indegree[G[cur][i]] =	= 0)
					Q.push(G[cur][i]);
			}
		}
		if(cnt > 0)	printf("CONFLICT\n");
		else if(flag)	printf("UNCERTAIN\n");
		else	printf("OK\n");
	}
	
	return 0;
} 
