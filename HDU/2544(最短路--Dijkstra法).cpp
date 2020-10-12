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
	int next;  //���ڽڵ� 
	int w;  //�ߵ�Ȩֵ  
};
vector <E> edge[105];  //�ڽӱ� ��vector: ���������飩 

int main() {
	while(~scanf("%d%d", &n, &m) && n+m) {
		//��ʼ���ڽӱ�
		for(int i=0; i<=n; i++)	edge[i].clear();
		//��������
		for(int i=0; i<m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			E e;
			e.next = b;
			e.w = c;
			edge[a].push_back(e);  // ��edge���ĩβ����һ��eԪ�� 
			e.next = a;  //����ͼ��������˫��ģ�push���� 
			edge[b].push_back(e);
		}
		//init
		memset(vis, 0, sizeof(vis));
		for(int i=1; i<=n; i++) {
			d[i] = -1;  //-1��ʾ���ɴ� 
		} 
		//��ʼ�ڵ�Ϊ1 
		d[1] = 0;
		vis[1] = 1;
		int P = 1;
		for(int i=1; i<n; i++) {
			for(int j=0; j<edge[P].size(); j++) {  //��������¼��뼯��K�еĽ��ֱ�����ڵı�
				int t = edge[P][j].next;
				int w = edge[P][j].w;
				if(vis[t])
					continue;
				if(d[t] == -1 || d[t] > d[P] + w)  //���ý���в��ɴ�,���߸ý����¼���Ľ�㾭��һ���ߵ���ʱ�������������
					d[t] = d[P] + w;
			}
			
			int minw = 1000000005;
			for(int j=1; j<=n; j++) {  //�������нڵ� 
				if(!vis[j]) {
					if(d[j] == -1)	continue;  //�в��ɴ� 
					if(d[j] < minw) {
						minw = d[j];
						P = j;
					}
				}
			}
			vis[P] = 1;  //����µĽڵ���뼯�� 
		} 
		printf("%d\n", d[n]);
	}
	
	return 0;
} 
