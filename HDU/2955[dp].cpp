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
		memset(dp,0,sizeof(dp));  //一定要初始化啊 
		//input
		cin>>p>>n;
		p = 1.0 - p;  //成功的概率 
		//注意所有的概率都要用1减，才是成功的概率 
		int sum = 0;
		for (int i=1; i<=n; i++) {
			cin>>M[i]>>P[i];
			P[i] = 1.0 - P[i]; 
			sum += M[i];  //总钱数 
		}
		//dp[i] 表示抢到钱数为 i 的情况下，成功（不被抓）的最大概率 
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
