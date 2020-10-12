#include <stdio.h>
//太奇怪了，使用G++是0MS，使用C是15MS 
//2020-08-14 10:31:07	Accepted	1220	0MS		1204K	174B	G++
//2020-08-14 10:31:23	Accepted	1220	15MS	1696K	174B	C
int main() {
	int n;
	while(~scanf("%d", &n)) {
		int cube = n*n*n;
		int res = (cube*(cube-1) >> 1) - 3*n*n*(n-1);
		printf("%d\n", res);
	}
	return 0;
}
