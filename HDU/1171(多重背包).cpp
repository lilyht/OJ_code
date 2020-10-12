#include <iostream>
#include <string.h>
using namespace std;
//2020-08-16 17:45:40	Accepted	1171	46MS	1984K	670 B	G++
int n;
int v[105], m[105];
int vv[10005];
int dp[150005];

int main() {
	while(cin>>n && n>0) {
		int sum = 0;
		for(int i=1; i<=n; i++) {
			cin>>v[i]>>m[i];
			sum += v[i] * m[i];
		}
		//·Ö×é
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			int r = 1;
			while(m[i] > r) {
				m[i] -= r;
				vv[++cnt] = r * v[i];
				r = r << 1;
			}
			if(m[i] > 0)
				vv[++cnt] = m[i] * v[i];
		}
		//dp
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=cnt; i++) {
			for(int j=sum/2; j>=vv[i]; j--) {
				dp[j] = max(dp[j], dp[j-vv[i]] + vv[i]);
			}
		} 
		cout<<sum - dp[sum/2]<<" "<<dp[sum/2]<<endl;
	}
	
	return 0;
} 
