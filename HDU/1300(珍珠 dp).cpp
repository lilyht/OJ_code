#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 110;
//2020-09-18 23:34:14	Accepted	1300	0MS	1392K	812B	G++ 
int a[MAXN];  //ÿ��������Ҫ������ 
int p[MAXN];  //ÿ�ֻ�����ļ۸� 
int sum[MAXN];  //ǰi�����������Ŀ 
int dp[MAXN];
int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		memset(sum, 0, sizeof(sum));
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>p[i];
			sum[i] = sum[i-1] + a[i];
		}
		//dp[i][j]�ĵ�һά����ѡ����i��������
		//�ڶ�άj��ȡ1~i������ӵ�j�ֿ�ʼ������Ǽ۸ߵ���������
		//ת�Ʒ��̣�dp[i] = min(dp[i], dp[j] + p[i]*(10 + sum[i]-sum[j])) 
		dp[0] = 0;
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=i; j++) {  //ע�⣺j�Ǵ�0��ʼ������1��ʼ���� 
				dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j] + 10)*p[i]);
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
