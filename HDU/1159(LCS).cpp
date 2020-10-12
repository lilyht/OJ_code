#include <iostream>
#include <string.h>
using namespace std;
//LCS：最长公共子序列 
//2020-08-20 10:35:39	Accepted	1159	124MS	5360K	491 B	G++
int dp[1005][1005];

int main() {
	string a, b;
	while(cin>>a>>b) {
		a = " " + a;
		b = " " + b;
		int la = a.length();
		int lb = b.length();
		memset(dp, 0, sizeof(dp));
//		if(a[0] == b[0])	dp[0][0] = 1;
		for(int i=1; i<la; i++) {
			for(int j=1; j<lb; j++) {
				if(a[i] == b[j])
					dp[i][j] = dp[i-1][j-1] +1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		cout<<dp[la-1][lb-1]<<endl;
	}
	
	return 0;
}
