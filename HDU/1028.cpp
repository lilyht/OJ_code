#include <iostream>
using namespace std;
int n;
int dp[122][122];
/*My question is how many different equations you can find for a given N.
  For example, assume N is 4, we can find:
  4 = 4;
  4 = 3 + 1;
  4 = 2 + 2;
  4 = 2 + 1 + 1;
  4 = 1 + 1 + 1 + 1;
  so the result is 5 when N is 4. Note that "4 = 3 + 1" and "4 = 1 + 3" is the same in this problem. Now, you do it!"
*/

/*
 对于j<i的时候的转移方程可以这么理解：
 如果我要求dp[5][3]， 那么我可以先加上dp[5][2]也就是最大数不超过2的划分；
 然后接下来我要加上的若干个划分每个划分中至少包括一个3，而且最大的是3
 ，那么对于这若干个划分任意一个划分去掉3的话，就变成了5-3的最大数不超过3的划分的个数 --> 即有dp[5][3] = dp[5][2]+dp[2][3].
*/

int main(){
	// dp[i][j] 表示将i划分成最大数不超过j的划分数
	for(int i=0; i<122; i++)	dp[0][i] = dp[1][i] = 1;
	for(int i=0; i<122; i++)	dp[i][1] = 1;
	for(int i=2; i<122; i++){
		for(int j=2; j<122; j++){
			if(i < j)	dp[i][j] = dp[i][j-1];
			else	dp[i][j] = dp[i][j-1] + dp[i-j][j];  // dp[i][j - 1]表示最大数不超过j-1的方案数, dp[i - j][j]表示拿出一个j后最大数不超过j的方案数 
		}
	}
	for(int i=1; i<20; i++) {
		for(int j=1; j<20; j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	while(cin>>n){
		cout<<dp[n][n]<<endl;
	}
	return 0;
}
