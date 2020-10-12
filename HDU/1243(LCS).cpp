#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2105;
int a[27];  //记录价值 
int dp[MAXN][MAXN];  //记录最大价值 
//2020-08-20 11:30:49	Accepted	1243	936MS	18756K	833 B	G++
int main() {
	int n, val;
	string order, s, t;
	while(cin>>n) {
		cin>>order;
		for(int i=0; i<n; i++) {
			cin>>val;
			a[order[i]-'a'] = val;
		}
		cin>>s>>t;
		s = " " + s;  t = " " + t;
		int lens = s.length();
		int lent = t.length();
		
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<lens; i++) {
			for(int j=1; j<lent; j++) {
				if(s[i] == t[j]) { 
					dp[i][j] = dp[i-1][j-1] + a[s[i]-'a'];
				}
				else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		cout<<dp[lens-1][lent-1]<<endl;
	}
	
	return 0;
}
/*
3
abz
1 2 26
abzabz
abzbza
*/
