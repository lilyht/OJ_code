#include <iostream>
#include <cstring>
using namespace std;
// dp[i]��ʾ��a[i]��β�����������е����ֵ
//��ôdp[j]=max(dp[j],dp[i]+a[j])  (a[i]<a[j])
int a[1005];
int dp[1005];

int main() {
	int n;
	while(cin>>n) {
		if(n == 0)	break;
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			dp[i] = a[i];  //û�г�ʼ��Ҳ���� 
		}
		for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
            if(a[j] > a[i])
                dp[j] = max(dp[i]+a[j], dp[j]);
        	}
        }
        int minn = 0;
        for(int i=1; i<=n; i++)
            minn = max(minn, dp[i]);
        cout<<minn<<endl;
	}
	
	return 0;
} 
