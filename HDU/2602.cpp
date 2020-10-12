#include <iostream>
#include <string.h>
using namespace std;
//2020-08-16 11:32:02	Accepted	2602	62MS	1412K	445 B	G++
//dp
int t;
int v[1005];
int w[1005];
int dp[1005];

int main() {
	cin>>t;
	while(t--) {
		int n, V;
		cin>>n>>V;
		for(int i=1; i<=n; i++)	cin>>v[i];  //��ֵ 
		for(int i=1; i<=n; i++)	cin>>w[i];  //��� 
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++) {
			for(int j=V; j>=w[i]; j--) {
				dp[j] = max(dp[j], dp[j-w[i]] + v[i]);  //ע���ǵ����
				/* 
				 * Ҫ����ÿ����ѭ������v=V..0��˳����dp[v]�� 
				 * �������ܱ�֤��dp[v]ʱ��dp[v-c[i]]�������״̬ dp[i-1][v-c[i]]��ֵ��
				 */ 
			}
		}
		cout<<dp[V]<<endl;
	}
	return 0;
}
