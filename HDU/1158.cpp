#include <iostream>
#include <cstring>
using namespace std;
// http://blog.sina.com.cn/s/blog_7ef869630100uwmr.html
// dp[i][j]表示第i个月，雇佣j个人时，这i个月的花销
int dp[15][100];
int need[15];

int main() {
	int m, hire, fire, salary;
	while(cin>>m && m) {
		memset(need, 0, sizeof(need));
		cin>>hire>>fire>>salary;
		for(int i=0; i<m; i++)
			cin>>need[i];
		
		
	}
	return 0;
} 
