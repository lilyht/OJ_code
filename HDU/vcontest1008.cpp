#include <iostream>
#include <string.h>
using namespace std;

int a[1005];
int main() {
	int n, x, idx, ans;
	while(scanf("%d", &n) && n) {
		memset(a, 0, sizeof(a));
		for(int i=0; i<=n; i++) {
			scanf("%d", &x);
			a[x]++;
			if(a[x] == 2) {
				idx = i;
				ans = x;
//				cout<<"i: "<<i<<endl;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
