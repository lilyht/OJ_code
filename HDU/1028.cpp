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
 ����j<i��ʱ���ת�Ʒ��̿�����ô��⣺
 �����Ҫ��dp[5][3]�� ��ô�ҿ����ȼ���dp[5][2]Ҳ���������������2�Ļ��֣�
 Ȼ���������Ҫ���ϵ����ɸ�����ÿ�����������ٰ���һ��3������������3
 ����ô���������ɸ���������һ������ȥ��3�Ļ����ͱ����5-3�������������3�Ļ��ֵĸ��� --> ����dp[5][3] = dp[5][2]+dp[2][3].
*/

int main(){
	// dp[i][j] ��ʾ��i���ֳ������������j�Ļ�����
	for(int i=0; i<122; i++)	dp[0][i] = dp[1][i] = 1;
	for(int i=0; i<122; i++)	dp[i][1] = 1;
	for(int i=2; i<122; i++){
		for(int j=2; j<122; j++){
			if(i < j)	dp[i][j] = dp[i][j-1];
			else	dp[i][j] = dp[i][j-1] + dp[i-j][j];  // dp[i][j - 1]��ʾ�����������j-1�ķ�����, dp[i - j][j]��ʾ�ó�һ��j�������������j�ķ����� 
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
