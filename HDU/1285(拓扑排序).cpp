#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
//HDU	Accepted	1285	15MS	1440K	1051 B	G++
int n, m, a, b;
int indegree[505];
vector<int> G[505];  //�ڽӱ� 
priority_queue<int, vector<int>, greater<int> > Q;  //��Ϊ���˳���С��������ʹ�����ȶ��� 

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
		//C++�е�queue�����ǲ�֧��clear����������ֶ���� 
		while(!Q.empty())	Q.pop();
		//ͳ�����нڵ����ȣ������Ϊ0�ļ������Q
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
			//����ڵ�cur���ڵĽڵ���ȼ�1��һ�� G[cur].size()�� 
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
