#include <iostream>
#include <string.h>
using namespace std;
//2020-08-18 11:11:25	Accepted	1541	62MS	3724K	841 B	G++
#define lowbits(k) k&(-k)
const int MAXN = 300000;
int level[MAXN];
int c[MAXN];

int getSum(int x) {
	int res = 0;
	for(int i=x; i>0; i-= lowbits(i)) {
		res += c[i];
	}
	return res;
}

void add(int x, int v) {
	for(int i=x; i<=MAXN; i+= lowbits(i)) {
		c[i] += v;
	}
}

int main() {
	int n, x, y;
	while(~scanf("%d", &n)) {
		memset(c, 0, sizeof(c));
		memset(level, 0, sizeof(level));
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &x, &y);
			//因为是按照顺序输入的, 那么完全不用管y，只用算出前面出现过的横坐标不大于当前星星的数目就是当前星星的level 
			x++;  //树状数组都是从1开始，而输入的坐标可能为0
			level[getSum(x)] ++;  //横坐标为x+1的星星水平为sum(x)
			add(x, 1);  //横坐标为x+1的星星数目 +1
		}
		for(int i=0; i<n; i++)
			printf("%d\n", level[i]);
		
	}
	return 0;
}
