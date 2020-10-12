#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> v[500010];
int cnt[500010];
int sum = 0, ans = 0, n;
//2020-09-16 10:13:32	Accepted	6867	530MS	36760K	801 B	G++
void dfs(int n1) {
	cnt[n1] = 1;
	for(int i=0; i<v[n1].size(); i++) {
		dfs(v[n1][i]);
		cnt[n1] += cnt[v[n1][i]];
	}
	sum += cnt[n1];
}

void dfs1(int n1, int s) {
	ans = max(ans, s);
	for(int i=0; i<v[n1].size(); i++) {
		dfs1(v[n1][i], s+n-cnt[v[n1][i]]);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) v[i].clear(), cnt[i]=0;
		for(int i=2; i<=n; i++) {
			int a;
			cin>>a;
			v[a].push_back(i);
		}
		sum = 0;
		dfs(1);
		ans = 0;
		dfs1(1, sum);
		cout<<ans<<endl;
	}
	return 0;
}
