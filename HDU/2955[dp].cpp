#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int M[105];
float P[105];
float dp[10005];

int main() {
	int casenum = 0;
	cin>>casenum;
	while(casenum--) {
		float p = 0.0;
		int n = 0;
		memset(dp,0,sizeof(dp));  //һ��Ҫ��ʼ���� 
		//input
		cin>>p>>n;
		p = 1.0 - p;  //�ɹ��ĸ��� 
		//ע�����еĸ��ʶ�Ҫ��1�������ǳɹ��ĸ��� 
		int sum = 0;
		for (int i=1; i<=n; i++) {
			cin>>M[i]>>P[i];
			P[i] = 1.0 - P[i]; 
			sum += M[i];  //��Ǯ�� 
		}
		//dp[i] ��ʾ����Ǯ��Ϊ i ������£��ɹ�������ץ���������� 
		dp[0] = 1; 
		for (int i=1; i<=n; i++) {
			for (int j = sum; j >= M[i]; j--) {
				dp[j] = max(dp[j], dp[j-M[i]] * P[i]);
//				cout<<"i: "<<i<<"---dp["<<j<<"]: "<<dp[j]<<endl;
			}
		} 
		int k = sum;
		for (k = sum; k>=0; k--) {
			if (dp[k] >= p)  break;
		}
		cout<<k<<endl;
	}
	return 0;
}
