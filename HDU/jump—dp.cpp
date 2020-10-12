#include <iostream>
#include <string.h>
using namespace std;
//LIS  Super Jumping! Jumping! Jumping!
//2020-08-19 13:56:03	Accepted	1087	31MS	1408K	492B	G++
int a[1005], dp[1005];

int main() {
	int n;
	while(cin>>n && n) {
		memset(a, 0, sizeof(a));
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			dp[i] = a[i];
		}
		//dp¡ª¡ªLIS 
		dp[0] = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<i; j++) {
				if(a[i] > a[j])
					dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
		int res = 0;
		for(int i=1; i<=n; i++) {
			if(dp[i] > res)
				res = dp[i];
		}
		cout<<res<<endl;
	}
	return 0;
}
