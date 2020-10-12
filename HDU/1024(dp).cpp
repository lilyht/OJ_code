#include <stdio.h>
#include <cmath> 
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
//language: G++ 
/* �ο� https://blog.51cto.com/13688928/2117013
 * dp[i][j]��ʾ��ǰj�����У���a[j]��β����Ϊi�ε�����
 * ״̬ת�ƹ�ʽ��dp[i][j] = max(dp[i-1][k], dp[i][j-1]) + a[j]
 * �ֱ��ʾ a[j] �����ɶκ� a[j] ������ a[j-1] ��β��һ��
 */
int a[1000005];
int dp[1000005];
int maxx[1000005];

int main() {
	int m, n;
	while(~scanf("%d%d", &m, &n)) {
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		memset(maxx, 0, sizeof(maxx));
		
		int maxsum;
		for(int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		for(int i=1; i<=m; i++) {
			maxsum = -99999999;
			for(int j=i; j<=n; j++) {
				dp[j] = max(dp[j-1], maxx[j-1]) + a[j];
				maxx[j-1] = maxsum;  //����Ϊʲô��ôд������ע�͵���д����ʲô��ͬ����̫��� 
				maxsum = max(maxsum, dp[j]);
//				maxx[j] = maxsum;
			}
		}
		printf("%d\n", maxsum);
	} 
	return 0;
} 
