#include<stdio.h>
//2020-09-07 11:19:16	Accepted	2018	0MS	1236K	309 B	G++	
int main() {
	int n;
	while(scanf("%d", &n) && n != 0) {
		int i, sum = 0;
		int a[10000] = {0,1,1,1,1};
		for(i=5; i<=n; i++) {
			a[i] = a[i-3]+a[i-1];//第i天 增长 的牛
		}
		if(n<=4)
			sum=n;
		else {
			for(i=1; i<=n; i++)
				sum = a[i] + sum;//累加起来
		}
		printf("%d\n", sum);
	}
}
