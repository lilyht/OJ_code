#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
//2020-08-23 17:17:13	Accepted	1861	15MS	1376K	851 B	G++ 
typedef struct {
	bool flag;
	int t;
}ship;
ship a[105];

void init() {
	for (int i = 0; i <= 100; i++)
		a[i].flag = false, a[i].t = 0;
}

int main() {
	int cnt, sumt;
	int j, h, m;
	char c;
	while(true) {
		cnt = 0;
		sumt = 0;
		init();
		while(true) {
			scanf("%d", &j);
			if(j == -1)
				return 0;
			scanf(" %c %d:%d", &c, &h, &m);  //� 
			if(c == 'S') {
				a[j].flag = true;
				a[j].t = h*60 + m;
			} else if(a[j].flag) {  //E 
				cnt++;  //������¼������ 
				sumt += h*60+m - a[j].t;
				a[j].flag = false;  //һ������������ 
			}
			if(j == 0)
				break;
		}
		if(cnt != 0)  //ceil(x)���ص��Ǵ���x����С������ceil()��������������룬ceil(-10.5) == -10 
			printf("%d %d\n", cnt, (int)ceil(sumt/(1.0*cnt)));
		else
			printf("0 0\n");
	}

	return 0;
}
