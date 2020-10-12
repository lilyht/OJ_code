#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 2020;
//2020-09-18 19:44:23	Accepted	5534	187MS	1424K	889B	G++
int f[MAXN];
int dp[MAXN];
int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<n; i++)	cin>>f[i];
		//n����������n-1���ߣ���������Ϊ2n-2��
		//����Ϊÿ�����Ķ�������Ϊ1,��������ÿ�����Ķ���Ϊ1��ʣ��n-2�ĵĶ����ٷ����
		//����[2, 3, ..., n-1]��Щ����
		//����[1,...,n-2]
		//��ֵ��[f(2),...,f(n-1)]
		//ÿһ�ֶȿ����úܶ�Σ���ȫ��������
		memset(dp, 0, sizeof(dp));
		dp[0] = f[1] * n;  //һ��ʼ��dp[0]��ʼ��Ϊ���еĵ㶼��һ�ȶ������valueֵ
		for(int i=2; i<=n-1; i++)  //�Ӷ��ȶ��㵽n-1�ȶ��㿪ʼѭ��dp
			for(int j=i-1; j<=n-2; j++)  //���ֻ�� n-2 ��������Խ��е���
				dp[j] = max(dp[j], dp[j-i+1] + f[i] - f[1]);     //����һ������Ϊi�Ķ���
				//һ��ʼ�������еĶ��㶼��һ�ȶ��㣬����ʹ�õ�cost�� i-1 �����õ���valueֵ�� f[i]-f[1]
		cout<<dp[n-2]<<endl;
	}
	return 0;
}
