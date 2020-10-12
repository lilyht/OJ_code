# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
using namespace std;
//2020-09-16 09:05:37	Accepted	6887	15MS	1388K	688 B	G++ 
struct Node {
	int x;
	int id;
}N[1213213];


bool cmp(struct Node a,struct Node b) {
	if (a.x == b.x)	
		return a.id<b.id;
	return a.x > b.x;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n,m,k;
		scanf("%d%d%d", &n, &m, &k);
		for(int i=1; i<=n; i++) {
			scanf("%d", &N[i].x);
			N[i].id = i;
		}
		if(k == 0) {
			for(int i=1; i<=n; i++) {
				printf("%d", i);
				if(i!=n)	printf(" ");
			}
			printf("\n");
			continue;
		}
		sort(N+1, N+n+1, cmp);
		for(int i=1; i<=n; i++) {
			printf("%d", N[i].id);
			if(i != n)	printf(" ");
		}
		printf("\n");
	}
	return 0;
}
