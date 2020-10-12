#include <iostream>
#include <string.h>
using namespace std;
//prim
//�����װ���ǰǰ�����5��Ź� 
//2020-08-23 09:36:18	Accepted	1863	0MS	1440K	1114 B	G++
const int inf = 0x7fffffff;
int mp[105][105];
int vis[105];
int dis[105];

int main() {
	int n, m, a, b, c;
	while(cin>>n>>m && n != 0) {
		//init
		for(int i=0; i<=m; i++) {
			vis[i] = 0;
			dis[i] = inf;
			for(int j=0; j<=m; j++) {
				mp[i][j] = inf;
			}
		}
		//input
		for(int i=1; i<=n; i++) {
//			mp[i][i] = 0;
			cin>>a>>b>>c;
			mp[a][b] = mp[b][a] = min(c, mp[a][b]);
		}
		//�����ʼ�ڵ�
		vis[1] = 1;
		dis[1] = 0;  // 
		int ans = 0;
		//init
		for(int i=1; i<=m; i++)
			dis[i] = mp[1][i];  //��ʼ��Ϊ1���ڵ�ľ���
		
		//������
		int x;
		bool flag = 0;
		for(int i=1; i<m; i++) {
			int temp = inf;
			for(int j=1; j<=m; j++) {
				if(!vis[j] && dis[j] < temp) {
					temp = dis[j];
					x = j;
				}
			}
			if(temp == inf) {  //�ⲿ��һ��ʼûд����WA�� 
				flag = 1;  //�������
				break;
			}
            	
			vis[x] = 1;
			ans += temp;
			//update
			for(int j=1; j<=m; j++) {
				if(!vis[j] && dis[j] > mp[x][j]) {
					dis[j] = min(dis[j], mp[x][j]);
				}
			}
		}
		if(flag != 1)  //�ж�����ҲҪע�� 
			cout<<ans<<endl;
		else
			cout<<"?"<<endl;
	}
	
	return 0;
}
