#include <iostream>
#include <string.h>
#include <algorithm> //max��ͷ�ļ� 
using namespace std;
const int MAXN = 100005;
//2020-08-31 16:54:01	Accepted	1176	62MS	6068K	623 B	G++
int dp[MAXN][12];

int main() {
	int n, x, t, maxt;
	while(~scanf("%d", &n) && n) {
		memset(dp, 0, sizeof(dp));
		maxt = 0;
		for(int i=0; i<n; i++) {
			scanf("%d%d", &x, &t);
			x++;  //�� 0~10 ת��Ϊ 1~11 
			dp[t][x]++;
			maxt = max(maxt, t) ;
		}
		//dp�ĵ�һά��ʱ�䣬�ڶ�ά�����꣬��ʾ�����ܽӵ�С�����ĸ��� 
		//���ű���ʱ�䣬Ȼ�����ÿһ��λ��
		for(int i=maxt; i>=0; i--) {
			for(int j=1; j<=11; j++) {
				dp[i][j] += max(dp[i+1][j], max(dp[i+1][j-1], dp[i+1][j+1]));
			}
		}
		printf("%d\n", dp[0][6]);
	}
	return 0;
}
