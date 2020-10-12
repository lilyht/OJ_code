#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 
int a[101], c[101];
int dp[100001];
int w[1001];

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m), n+m){
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		memset(dp, 0, sizeof(dp));  //��ʼ��״̬0Ϊ�ɴ� 
		dp[0] = 1;
		for(int i=0; i<n; i++)	scanf("%d", &a[i]);  //Ӳ�Ҽ�ֵ 
		for(int i=0; i<n; i++)	scanf("%d", &c[i]);  //Ӳ������ 
		int x = 0;
		int cnt = 0;
		//ÿ��Ӳ�ҷ��� 
		for(int i=0; i<n; i++){
			for(int j=1; c[i]>0; j *= 2){
				x = min(j, c[i]);
				c[i] -= x;
				w[cnt++] = a[i]*x;  //�÷����Ӳ�Ҽ�ֵ Ϊ������ֵ����������Ʒ����x 
			}
		}
		//ת��Ϊ0/1����������� 
		for(int i=0; i<cnt; i++){
			for(int j=m; j>=w[i]; j--){
				if(dp[j-w[i]])	//���j-w[i]״̬�ǿɴ�ģ������ת�� 
					dp[j] = 1;
			}
		}
		int ans = 0;
		for(int i=1; i<=m; i++){
			ans += dp[i];
		}
		printf("%d\n", ans);
		
	}
	
	return 0;
}
