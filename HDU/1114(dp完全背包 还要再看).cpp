#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

//��ȫ�������� 
//ע��ϸ�ڣ�����
//dp�����ʼ����Ҫ��ʼ��Ϊ������
//��������ѭ���������ѭ������һ���м���Ӳ�ң��ڲ���ѭ���Ǵ�����Ӳ�ҵ����࿪ʼ��һ��ֱ�������Ͻ� 

struct coin{
	int v;
	int w;
}a[505];

int dp[10005];

int main() {
	int T, E, F, n, cap, temp;
	cin>>T;
	while(T--) {
		cin>>E>>F>>n;
		cap = abs(F - E);
		for(int i=0; i<n; i++)
			cin>>a[i].v>>a[i].w;
		
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		
		for(int i=0; i<n; i++) {
			for(int j=a[i].w; j<=cap; j++) {  //��ȫ������һά��������ö�ٵ� 
				dp[j] = min(dp[j], dp[j-a[i].w] + a[i].v);
			}
		}
		if(dp[cap] != dp[10004])
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[cap]<<"."<<endl;
		else
			cout<<"This is impossible."<<endl;
		cout<< dp[10004];
	}
	return 0;
} 
