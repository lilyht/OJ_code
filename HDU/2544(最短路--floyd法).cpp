#include <iostream>
using namespace std;
#define INF 1000005
//ע�����INF���岻�ܹ��󣬷�������ӵ�ʱ�����������һ�㶨��Ϊ�����бߵĺʹ�һ���Ϳ� 
//floyd
//HDU	Accepted	2544	62MS	1464K	626 B	G++ 
int n, m; 
int dist[105][105];

void floyd() {
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main() {
	int a, b, c;
	while(~scanf("%d%d", &n, &m) && n+m) {
		//init
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=n; j++)
				dist[i][j] = INF;
			dist[i][i] = 0;
		}
		
		for(int i=0; i<m; i++) {
			cin>>a>>b>>c;
			dist[a][b] = dist[b][a] = c;
		}
		
		floyd();
		
		printf("%d\n", dist[1][n]);
	}
	return 0;
} 
