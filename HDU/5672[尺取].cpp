#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<string.h>
using namespace std;

int t, k, sum, i, j;
long long ans;
int vis[30];
const int maxn = 1e6+50;
char s[maxn];  //记 

int change(char c) {
	return (int)c - 'a';
}

int main() {
	scanf("%d",&t);
	while(t--) {
		i = 0;
		j = 0;
		ans = 0;
		sum = 0;
		memset(vis,0,sizeof(vis));
		scanf("%s%d", s, &k);
		int n = strlen(s);
		while(1) {
			while(j<n && sum<k) {
				if(!vis[change(s[j])])  //如果刚刚数过加入一个新的字符
					sum++;
				vis[change(s[j])]++;
				j++;
			}//while
			if(sum<k || j>n)	break;
			ans += n-j+1;  //从这个子字符串开始，每往后多加一个字母，都符合题意 
			
			vis[change(s[i])]--;
			if(!vis[change(s[i])])
				sum--;  // 如果最小左端点代表的字符去掉之后字串字符的个数没有了，字符个数减一
			i++;  //左区间右移一位 
		}//while(1)
		printf("%lld\n", ans);
	}
	return 0; 
}


