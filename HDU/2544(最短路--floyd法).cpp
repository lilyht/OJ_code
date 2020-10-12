#include <iostream>
using namespace std;
#define INF 1000005
//注意这个INF定义不能过大，否则在相加的时候容易溢出，一般定义为比所有边的和大一点点就可 
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
