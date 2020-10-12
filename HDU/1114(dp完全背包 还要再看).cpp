#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

//完全背包问题 
//注意细节！！！
//dp数组初始化是要初始化为大数字
//另外两层循环，外面的循环控制一共有几种硬币，内部的循环是从这种硬币的种类开始加一，直到到达上界 

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
			for(int j=a[i].w; j<=cap; j++) {  //完全背包的一维都是正向枚举的 
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
