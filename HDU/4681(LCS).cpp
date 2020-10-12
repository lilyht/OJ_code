#include <bits/stdc++.h> 
using namespace std;
//2020-08-20 17:00:22	Accepted	4681	280MS	9364K	1995 B	G++

const int MAXN = 1005;
int la, lb, lc;
int dp[MAXN][MAXN];
int rev_dp[MAXN][MAXN];
string a, b, c;
vector<pair<int, int> > p1, p2;

void init() {
	memset(dp, 0, sizeof(dp));
	memset(rev_dp, 0, sizeof(rev_dp));
	//前向 
	for(int i=1; i<la; i++) {
		for(int j=1; j<lb; j++) {
			if(a[i] == b[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	//反向
	for(int i=la-1; i>=1; i--) {
		for(int j=lb-1; j>=1; j--) {
			if(a[i] == b[j])
				rev_dp[i][j] = rev_dp[i+1][j+1] + 1;
			else
				rev_dp[i][j] = max(rev_dp[i+1][j], rev_dp[i][j+1]);
		}
	}
}

void findsub(string s, int lens, string target, int lent, vector<pair<int,int> >&p) {
	p.clear();
	int k = 1;
	int j = 1;
	for(int i=1; i<lens; i++) {
		k = 1;
		if(s[i] != target[k])
			continue;
		for(j=i; j<lens; j++) {
			if(s[j] == target[k])
				k++;
			if(k >= lent)
				break;
		}
		if(k >= lent) {
//			cout<<"边界：i: "<<i<<", j: "<<j<<endl;
			p.push_back(make_pair(i, j));  //在字符串s中，子串c的开始和结束坐标 
		}
			
	}
}

int main() {
	int t;
	cin>>t;
	int kse = 1;
	while(t--) {
		a = b = c = "";
		p1.clear();
		p2.clear();
		cin>>a>>b>>c;
		a = " " + a;
		b = " " + b;
		c = " " + c;
		la = a.length();
		lb = b.length();
		lc = c.length();
		
		init();
		findsub(a, la, c, lc, p1);
//		cout<<"-----"<<endl; 
		findsub(b, lb, c, lc, p2); 
		
		cout<<"Case #"<<kse<<": ";
		kse++;
		int ans = 0;
//		cout<<"p1.size() "<< p1.size()<<endl;
//		cout<<"p2.size() "<< p2.size()<<endl;
		for(int i=0; i<(int)p1.size(); i++) {
			for(int j=0; j<(int)p2.size(); j++) {
				ans = max(ans, lc-1 + dp[p1[i].first-1][p2[j].first-1] + rev_dp[p1[i].second+1][p2[j].second+1]);
//				ans = max(ans, lc + dp[p1[i].first-1][p2[i].first-1] + rev_dp[p1[i].second+1][p2[j].second+1]);
			}
		}
		cout<<ans<<endl;
//		for(int i=1; i<=la; i++) {
//			for(int j=1; j<=lb; j++) {
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	}
	return 0;
}
