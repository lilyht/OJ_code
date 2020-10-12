#include<bits/stdc++.h>
using namespace std;
//2020-08-26 17:15:30	Accepted	1204	0MS	1408K	399 B	G++
int n, m;
double p, q, win, lose, ans;
int main() {
	while(~scanf("%d%d %lf %lf", &n, &m, &p, &q)) {
		win = p*(1-q);
		lose = q*(1-p);
		if(m == 0)	ans = 1;
		else if(win == 0 || n == 0)	ans = 0;
		else if(win == lose)	ans = 1.0*n / (n+m);
		else	ans = (double)(1 - pow(lose/win, n)) / (1 - pow(lose/win, n+m));
		printf("%.2lf\n", ans);
	}
	return 0;
}
