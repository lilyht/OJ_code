#include <iostream>
#include <algorithm>
using namespace std;
//组合背包
//2020-08-16 22:22:12	Accepted	3591	93MS	1576K	1443 B	G++
//注意：因为vv数组和num数组长度设置小了，导致wa了三次 
#define inf 99999999
int n, t;
int v[105], c[105];
int vv[200005], num[200005];
int dp_buy[20005], dp_back[20005];

int main() {
	int kse = 0;
	while(cin>>n>>t && n+t) {
		kse++;
		for(int i=1; i<=n; i++)		cin>>v[i];
		for(int i=1; i<=n; i++)		cin>>c[i];
		int sum = 0;
		for(int i=1; i<=n; i++)
			sum += v[i] * c[i];
		fill(dp_buy, dp_buy+20005, inf);  //付钱 
		fill(dp_back, dp_back+20005, inf);  //找钱 
		//分组
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			int r = 1;
			while(c[i] > r) {
				c[i] -= r;
				vv[++cnt] = r * v[i];
				num[cnt] = r;
				r = r << 1;
			}
			if(c[i] > 0) {
				vv[++cnt] = c[i] * v[i];
				num[cnt] = c[i];
			}
		}
		//付钱的dp——多重背包，范围是 t ~ 20000 
		dp_buy[0] = 0;
		for(int i=1; i<=cnt; i++)
			for(int j=20000; j>=vv[i]; j--)
				dp_buy[j] = min(dp_buy[j], dp_buy[j-vv[i]] + num[i]);
//		cout<<"fukuan"<<endl;
//		for(int i=0; i<80; i++)
//			cout<<dp_buy[i]<<" "; 
//		cout<<endl;
		
		//找钱的dp——完全背包，范围是 1 ~ 20000  
		dp_back[0] = 0;
		for(int i=1; i<=n; i++)
			for(int j=v[i]; j<=20000; j++)
				dp_back[j] = min(dp_back[j], dp_back[j-v[i]] + 1);
		
		int minnum = inf;
		for(int i=t; i<=20000; i++) {
			if(dp_buy[i] + dp_back[i-t] < minnum)
				minnum = dp_buy[i] + dp_back[i-t];
		}
		if(minnum == inf)	cout<<"Case "<<kse<<": -1"<<endl;
		else	cout<<"Case "<<kse<<": "<<minnum<<endl;
	}
	return 0;
} 
