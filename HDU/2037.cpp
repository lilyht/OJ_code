#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 110;
//2020-09-17 17:09:00	Accepted	2037	15MS	1400K	578 B	G++ 
struct node{
	int s, e;
}a[MAXN];

bool cmp(node x, node y) {
	if(x.e != y.e)
		return x.e < y.e;
	else
		return x.s > y.s;
}

int main() {
	int n;
	while(cin>>n && n) {
		for(int i=0; i<n; i++) {
			cin>>a[i].s>>a[i].e;
		}
		sort(a, a+n, cmp);
		int ans = 1;
		int tmp = a[0].e;
		for(int i=1; i<n; i++) {
			if(a[i].s >= tmp) {
				ans++;
				tmp = a[i].e;  //主要是这里 
			}
				
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0

*/
