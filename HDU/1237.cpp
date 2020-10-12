#include <iostream>
#include <string.h>
using namespace std;
//2020-09-16 19:15:14	Accepted	1237	15MS	1412K	609 B	G++	
double a[160];
int main() {
	double num;
	char op;
	while(scanf("%lf", &num) != EOF) {
		int idx = 0;
		a[idx] = num;
		idx++;
		op = getchar();
		if(op == '\n' && num == 0) {
			break;
		}
		while(true) {
			scanf("%c %lf", &op, &num);
			if(op == '+')	a[idx++] = num;
			else if(op == '-')	a[idx++] = -1*num;
			else if(op == '*')	a[idx-1] = num * a[idx-1];
			else	a[idx-1] = a[idx-1] * 1.0 / num;
			if(getchar() == '\n')	break;
		}
		double ans = 0.0;
		for(int i=0; i<idx; i++) {
			ans += a[i];
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
