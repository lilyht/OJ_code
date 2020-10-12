#include <iostream>
#include <string.h>
using namespace std;
#define INF 0x7fffffff	// �ҿ��˾���Ϊ�����ʼ��������ȥ��0x3f̫С�� 

// Prim�㷨 

int n, k, cost;
char a, b;
int x = 0;
int d[30];
int vis[30];
int mp[30][30];  //������������

int main() {
	while(cin>>n && n) {
		//init
		memset(vis, 0, sizeof(vis));
		for(int i=1; i<=n; i++)	d[i] = INF;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				mp[i][j] = INF;		
		
		for(int i=1; i<n; i++) {
			cin>>a>>k;
			for(int j=0; j<k; j++) {
				cin>>b>>cost;
				mp[a-'A'+1][b-'A'+1] = mp[b-'A'+1][a-'A'+1] = cost;
			}
		}
		//prim
		int ans = 0;
		vis[1] = 1;  //���� 
		for(int i=1; i<=n; i++)  //����д����wa 
			d[i] = mp[i][1];
			
		for(int i=1; i<n; i++) {  //note: �ұ߽���i<n�������� <= ����Ϊ�ڵ�1�Ѿ��ӽ����� 
			int m = INF; 
			for(int j=1; j<=n; j++)
				if(!vis[j] && d[j] < m)
					m = d[x = j];
			vis[x] = 1;
			ans += m;
			for(int j=1; j<=n; j++)
				if(!vis[j])
					d[j] = min(mp[j][x], d[j]);
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
