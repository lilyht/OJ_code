#include <iostream>
#include <cstring>
using namespace std;
// http://blog.sina.com.cn/s/blog_7ef869630100uwmr.html
// dp[i][j]��ʾ��i���£���Ӷj����ʱ����i���µĻ���
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
