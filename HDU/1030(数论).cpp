#include <stdio.h>
#include <math.h>

int n, m;

int main() {
	while(~scanf("%d%d", &m, &n)) {
		int layern = sqrt(n-1) + 1;
		int layerm = sqrt(m-1) + 1;
		int leftn = (n - pow(layern-1, 2) + 1) / 2; 
		int rightn = (layern*layern - n) >> 1;
		int leftm = (m - pow(layerm-1, 2) + 1) / 2; 
		int rightm = (layerm*layerm - m) >> 1;
		int res = abs(layern - layerm) + abs(leftn - leftm) + abs(rightn - rightm);
		printf("%d\n", res);
	}
	return 0;
}
