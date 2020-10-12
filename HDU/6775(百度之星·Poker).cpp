#include <bits/stdc++.h>
using namespace std;
//2020-09-14 13:09:56	Accepted	6775	780MS	1372K	301 B	G++ 
int main() {
	int t, n, m, p;  //×¢Òâ£ºpÊÇint 
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &m, &p);
		int cnt = 0;
		double cost = m - (int)(m*(100-p)/100.0);
		while(n >= m) {
			n -= cost;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}

