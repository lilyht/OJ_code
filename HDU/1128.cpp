#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1000050;
int a[MAXN] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
//2020-09-17 23:19:06	Accepted	1128	62MS	5244K	389 B	G++
 
int main() {
	for(int i=1; i<=1000000; i++) {
//		if(a[i] == 1) {  //没有这个判断！！self数字也可以生成 
		int x = i;
		int sum = i;
		while(x) {
			sum += x % 10;
			x = x / 10;
		}
		a[sum] = 1;
		if(!a[i])
			printf("%d\n", i);
//		}
	}
	return 0;
}
