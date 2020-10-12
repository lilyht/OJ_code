#include <iostream>
#include <string.h>
using namespace std;
//没做出来 

bool dp[110005][110005];

int main() {
	string s;
	while(cin>>s) {
		int len = s.length();
		int ans = 1;
		//初始化L为1和2的情况
		for(int i=0; i<len; i++) {
			dp[i][i] = 1;
			if(i <len -1) {
				if(s[i] == s[i+1]) {
					dp[i][i+1] = 1;
					ans = 2;
				}
			}
		}
		//dp
		for(int L=3; L<=len; L++) {
			for(int i=0; i<len; i++) {
				int j = i + L - 1;
				if(s[i] == s[j] && dp[i+1][j-1]) {
					dp[i][j] = 1;
					ans = L;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
