#include <iostream>
#include <string.h>
using namespace std;
//2020-09-21 15:37:57	Accepted	1390	0MS	1780K	435 B	G++
int a[100000];
int main() {
	int t, x ;
	cin>>t;
	while(t--) {
		int cnt = 0;
		int idx = 0;
		memset(a, 0, sizeof(a));
		cin>>x;
		while(x) {
			a[cnt++] = x % 2;
			x = x>>1;
		}
		//注意输出格式 
		bool flag = false;
		for(int i=0; i<cnt; i++) {
			if(a[i] == 1 && !flag) {
				cout<<i;
				flag = 1;
			}
			else if(flag && a[i] == 1) 
				cout<<" "<<i;
		}
		cout<<endl;
	}
	return 0;
}
