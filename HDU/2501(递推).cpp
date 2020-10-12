#include <iostream>
using namespace std;
//2020-09-07 10:42:32	Accepted	2501	0MS	1396K	249 B	G++	
//µİÍÆ 
int ans[32];
int main() {
	int n, x;
	cin>>n;
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 3;
	for(int i=3; i<=30; i++)
		ans[i] = ans[i-1] + ans[i-2]*2;
	while(n--) {
		cin>>x;
		cout<<ans[x]<<endl;
	} 
	return 0;
}
