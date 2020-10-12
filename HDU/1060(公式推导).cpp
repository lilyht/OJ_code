#include <stdio.h>
#include <math.h> 

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		if(n == 0) {
			printf("0\n");
			continue;
		}
		double a = n*log10(n);
		a = a - (long long)a;
		int l = (int)pow(10, a);
		printf("%d\n", l);
	}
	return 0;
}
