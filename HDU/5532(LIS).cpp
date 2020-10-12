#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
//2020-09-18 21:54:27	Accepted	5532	702MS	2160K	737 B	G++
//LIS：https://blog.csdn.net/wbin233/article/details/77570070 
int n;
int a[MAXN];
int dp[MAXN];

bool LIS1() {
	memset(dp, 0, sizeof(dp));
	int pos = 0;
	dp[0] = a[0];
	for(int i=1; i<n; i++) {
		if(a[i] >= dp[pos])  //主注意这里有=号！！！ 
			dp[++pos] = a[i];
		else  //注意这个是upper！！！ 
			dp[upper_bound(dp, dp+pos+1, a[i])-dp] = a[i];
	}
//	cout<<pos+1<<endl;
	if(pos+1 >= n-1)
		return true;
	else
		return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++)	scanf("%d", &a[i]);
		if(LIS1())
			printf("YES\n");
		else {
			reverse(a, a+n);
			if(LIS1()) {
				printf("YES\n");
			}
			else
				printf("NO\n");
		}
	}
	return 0;
} 
