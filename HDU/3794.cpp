#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
//2020-09-06 14:55:00	Accepted	3794	234MS	4404K	787 B	G++
//注意：__int64可以AC，long long就一直WA 
__int64 c[MAXN];
__int64 p[MAXN];

bool cmp(__int64 x, __int64 y) {
	return x > y;
}

bool cmp2(__int64 x, __int64 y) {
	return x < y;
}

int main() {
	__int64 nc, np;
	while(cin>>nc && nc >= 0) {
		for(__int64 i=0; i<nc; i++)
			scanf("%I64d", &c[i]);  //__int64的输入 
		cin>>np;
		for(__int64 i=0; i<np; i++)
			scanf("%I64d", &p[i]);
		sort(c, c+nc, cmp);
		sort(p, p+np, cmp);
		__int64 sum = 0;
		__int64 mini = min(nc, np);
		for(__int64 i=0; i<mini; i++) {
			if(c[i] < 0 || p[i] < 0)
				break;
			sum += c[i] * p[i];
		}
		sort(c, c+nc, cmp2);
		sort(p, p+np, cmp2);
		for(__int64 i=0; i<mini; i++) {				
			if(c[i] > 0 || p[i] > 0)
				break;
			sum += c[i] * p[i];
		}
		printf("%I64d\n",sum);  //__int64的输出 
	}
	return 0;
} 
