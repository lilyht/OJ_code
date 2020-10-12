#include <iostream>
#include <string.h>
using namespace std;
//2020-09-02 16:46:45	Accepted	5776	109MS	1800K	582B	G++
const int MAXM = 5005;
const int MAXN = 100005;
int nest[MAXM];
int a[MAXN];
int main() {
	int t, n, m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		int sum = 0;
		memset(nest, 0, sizeof(nest));
		for(int i=0; i<n; i++) {
			cin>>a[i];
			sum += a[i];  //Ç°×ººÍ 
			nest[sum % m]++;
		}
		if(n > m) {
			cout<<"YES"<<endl;
			continue;
		}
		bool flag = false;
		for(int i=0; i<m; i++) {
			if(nest[i] >= 2 || nest[0]) {
				flag = 1;
				break;
			}
		}
		if(flag)	cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	
	return 0;
}
/*
1
5 7
1 4 5 4 9
---------
YES
*/
