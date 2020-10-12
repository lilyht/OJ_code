#include <cstdio>
#include <cstring>
using namespace std;
int vis[501];
int match[501];
int map[501][501];
int u, v, n;

bool find(int k) {
	//找增广路
	for(int i=0; i<n; i++){
		if(vis[i] == 0 && map[k][i] == 1){
			vis[i] = 1;
			if(match[i] == -1 || find(match[i])){
				//找增广路，反向
				match[i] = k;
				return true;
			}
		}
	}
	return false;
}

int main() {
	while(~scanf("%d", &n)) {
		memset(map, 0, sizeof(map));
        memset(match, -1, sizeof(match));
		int x, num;
		for(int i=0; i<n; i++) {
			scanf("%d: (%d)", &u, &num);
			for(int j=0; j<num; j++) {
				scanf("%d", &v);
				map[u][v] = 1;
			}
		}
		int ans = 0;
		for(int i=0; i<n; i++){
			memset(vis, 0, sizeof(vis));
			if(find(i))
				ans++;
		} 
		printf("%d\n", n-ans/2);
	}
	
	return 0;
}
