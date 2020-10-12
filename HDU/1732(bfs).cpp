#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
//2020-08-14 16:05:57	Accepted	1732	218MS	46308K	2319 B	G++ 
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char mp[9][9];
bool vis[9][9][9][9][9][9][9][9];  //3������һ���˵�λ��Ϊһ��״̬   //ע�����ռ䣬֮ǰд�Ĳ���9��10�ͻ�MLE 

struct node{  //��ʾÿ��״̬�ĸ����������Ӽ�һ���ˣ����������� 
	int x[4];
	int y[4];
	int step;
};
node bgn;

int bfs() {
	node cur, nxt;
	queue<node> Q;
	while(!Q.empty())	Q.pop();
	Q.push(bgn);
	vis[bgn.x[0]][bgn.y[0]][bgn.x[1]][bgn.y[1]][bgn.x[2]][bgn.y[2]][bgn.x[3]][bgn.y[3]] = 1;
	
	while(!Q.empty()) {
//		cout<<Q.size()<<endl;
		cur = Q.front();
		Q.pop();
		//�жϳ���
		if(mp[cur.x[0]][cur.y[0]]=='@' && mp[cur.x[1]][cur.y[1]]=='@' && mp[cur.x[2]][cur.y[2]]=='@') {
			return cur.step;
		}
		for(int i=0; i<4; i++) {
			nxt = cur;
			nxt.x[3] += dx[i];  //����һ��
			nxt.y[3] += dy[i];
			if(nxt.x[3]>=0 && nxt.x[3]<n && nxt.y[3]>=0 && nxt.y[3]<m && mp[nxt.x[3]][nxt.y[3]] != '#') {
				//���ϳ�������
				bool flag = true;
				for(int j=0; j<3; j++) {
					if(nxt.x[3] == nxt.x[j] && nxt.y[3] == nxt.y[j]) {  //�ж����Ƿ��ߵ����ӵ�λ���� 
						//�����ӣ�������λ��Ϊԭλ�ü������ߵķ��� 
						nxt.x[j] += dx[i];
						nxt.y[j] += dy[i];
						if(nxt.x[j]>=0 && nxt.x[j]<n && nxt.y[j]>=0 && nxt.y[j]<m && mp[nxt.x[j]][nxt.y[j]] != '#') {
							//pass 
						}
						else {
							flag = false;
							break;  //��break����Ϊ���������������ط�����˵����ߵ�һ��λ���ϣ����λ�ö�Ӧֻ����һ�����ӡ�
									//������������Ӳ����������������ô˵��������ߵ������λ�þ�����Ч�ģ���������Ҳ�Ʋ��ˣ������break������continue 
						}
					}
					//*û�뵽�ĵط����ж���������ƶ����Ƿ��ƶ������������ӵĵط�* 
					for(int k=0; k<3; k++) {
						if(k!=j && nxt.x[k] == nxt.x[j] && nxt.y[k] == nxt.y[j]) {
							flag = false;  //���Ϊfalse 
							break;
						}
					}
				}
				if(!flag)  //�м������������� 
					continue;
				if(!vis[nxt.x[0]][nxt.y[0]][nxt.x[1]][nxt.y[1]][nxt.x[2]][nxt.y[2]][nxt.x[3]][nxt.y[3]]) {
					vis[nxt.x[0]][nxt.y[0]][nxt.x[1]][nxt.y[1]][nxt.x[2]][nxt.y[2]][nxt.x[3]][nxt.y[3]] = 1;
					nxt.step = cur.step + 1;
					Q.push(nxt);
				}
			}
		}
	}
	return -1;
}

int main() {
	while(cin>>n>>m) {
		int index = 0;
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>mp[i][j];
				if(mp[i][j] == 'X') {
					bgn.x[3] = i;
					bgn.y[3] = j;
				}
				if(mp[i][j] == '*') {
					bgn.x[index] = i;
					bgn.y[index] = j;
					index++;
				}
			}
		}
		bgn.step = 0;
		cout<<bfs()<<endl;
	}
	
	return 0;
}
