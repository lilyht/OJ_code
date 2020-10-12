#include <iostream>
#include <string.h>
using namespace std;
//2020-08-19 20:48:38	Accepted	5748	608MS	2560K	595 B	G++
//������LIS����֮ͬ������Ҫʹ��ans����浱ǰ��LIS���� 
int n;
int a[100005];
int dp[100005];
int ans[100005];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			dp[i] = 1; 
		}
		//dp
		int pos = 0;
		dp[0] = -1;
		for(int i=1; i<=n; i++) {
			if(dp[pos] < a[i]) {
				dp[++pos] = a[i];
				ans[i] = pos;
			} else {
				//ע�� lower_bound �Ĳ�����Χ������ 
				int idx = lower_bound(dp+1, dp+pos+1, a[i]) - dp;
				dp[idx] = a[i];
				ans[i] = idx;
			}
		}
		for(int i=1; i<=n; i++)
			i==n ? cout<<ans[i]<<endl : cout<<ans[i]<<" ";
		
	}
	return 0;
}
