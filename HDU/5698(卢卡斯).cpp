#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
const LL p = 1e9+7;

//参考博客：https://blog.csdn.net/sdauguanweihong/article/details/81662410 

//适用于p很大
LL quick_mod(LL a, LL b) {   //快速幂
	LL ans = 1;
	a %= p;
	while(b) {
		if(b & 1) {
			ans = ans * a % p;
			b--;
		}
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}

LL C(LL n, LL m) {    //求组合C（n，m）
	if(m > n)	return 0;    //n<m, c(n,m)=0
	LL ans = 1;
	for(int i=1; i<=m; i++) {
		LL a = (n + i - m) % p;
		LL b = i % p;
		ans = ans * (a * quick_mod(b, p-2) % p) % p;  //其实还不太明白 
	}
	return ans;
}

LL Lucas(LL n, LL m) {   //lucass定理
	if(m == 0)	return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main() {
	LL n,m;
	while(scanf("%I64d%I64d", &n, &m)!=EOF) {

		printf("%I64d\n", Lucas(m+n-4,m-2));
	}
	return 0;
}
