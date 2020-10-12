#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//2020-09-07 14:10:48	Accepted	2802	15MS	1256K	332 B	G++
//学会找找循环解 

__int64 f[110000];
void init() {
	int i;
	f[1] = 1;
	f[2] = 7;
	for(i=3; i<=5000; i++)
		f[i] = (f[i-2] + 3*i*i - 3*i + 1) % 2009;
}

int main() {
	__int64 n, i;
	init();
	while(scanf("%I64d", &n), n) {
//		for(i=3; i<=110000; i=i+2)//打表法找出循环节
//			if(f[i] == 1)
//				break;
//			printf("%I64d\n", i-1);
//		for(i=4; i<=110000; i=i+2)
//			if(f[i] == 7)
//				break;
//			printf("%I64d\n", i-2);
//		printf("%I64d\n",f[4018]);
		printf("%I64d\n", f[n%4018]);
	}
	return 0;
}
