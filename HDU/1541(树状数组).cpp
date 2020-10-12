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
			//��Ϊ�ǰ���˳�������, ��ô��ȫ���ù�y��ֻ�����ǰ����ֹ��ĺ����겻���ڵ�ǰ���ǵ���Ŀ���ǵ�ǰ���ǵ�level 
			x++;  //��״���鶼�Ǵ�1��ʼ����������������Ϊ0
			level[getSum(x)] ++;  //������Ϊx+1������ˮƽΪsum(x)
			add(x, 1);  //������Ϊx+1��������Ŀ +1
		}
		for(int i=0; i<n; i++)
			printf("%d\n", level[i]);
		
	}
	return 0;
}
