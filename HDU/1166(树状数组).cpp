#include <iostream>
#include <string.h>
using namespace std;
//2020-08-17 22:49:04	Accepted	1166	202MS	1764K	959 B	G++
 
#define lowbits(x) x&(-x)
const int MAXN = 50005;
int a[50005];
int c[50005];
char op[8];

int getSum(int x) {
	int sum = 0;
	for(int i=x; i>0; i -= lowbits(i)) {
		sum += c[i];
	}
	return sum;
}

void update(int idx, int x) {
	for(int i=idx; i<=MAXN; i+=lowbits(i)) {
		c[i] += x; 
	}
}

int main() {
	int t, n, idx, x;
	scanf("%d", &t);
	int kse = 0;
	while(t--) {
		//init
		memset(c, 0, sizeof(c));
		
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			update(i, a[i]);  //加入树状数组 
		}
		printf("Case %d:\n", ++kse);
		scanf("%s", op);
		while(op[0] != 'E') {
			scanf("%d%d", &idx, &x);
			if(op[0] == 'Q') {
//				printf("===\n");
				printf("%d\n", getSum(x) - getSum(idx-1));
			}
			else if(op[0] == 'A') {
				update(idx, x);
			}
			else if(op[0] == 'S') {
				update(idx, -1 * x);
			}
//			else
//				printf("else\n");
			scanf("%s", op);
		}
	}
	return 0;
}
