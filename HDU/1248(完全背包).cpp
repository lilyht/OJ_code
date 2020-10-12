#include <iostream>
#include <string.h>
using namespace std;
//2020-09-19 22:34:29	Accepted	1248	15MS	1432K	312 B	G++
int a[3] = {150, 200, 350};
int dp[10010];
int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<3; i++) {
			for(int j=a[i]; j<=n; j++) {
				dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
			}
		}
		cout<<n - dp[n]<<endl;
	} 
	return 0;
}
