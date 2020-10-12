#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
//2020-09-17 10:58:00	Accepted	1338	46MS	1412K	530B	G++
//²Î¿¼²©¿Í£ºhttps://blog.csdn.net/nameofcsdn/article/details/52203049 
int a[MAXN];
int n, m;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int x;
	int kse = 1;
	while(cin>>n>>m && n+m) {
		for(int i=0; i<m; i++)
			cin>>a[i];
		
		sort(a, a+m, cmp);
		int fail = 0;
		for(int i=0; i<m; i++) {
			if(a[i] < m*n-i-fail) {
				fail++;
			}
		}
		cout<<"Case "<<kse<<": ";
		kse++;
		cout<<m-fail<<endl;
	}
	return 0;
}
/*
2 5
1 7 2 10 9

6 11
62 63 54 66 65 61 57 56 50 53 48

0 0

*/ 
