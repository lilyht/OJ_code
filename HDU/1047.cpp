#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
//注意特殊输入，如00的情况 
using namespace std;
int ans[1000];
int maxlen;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		memset(ans, 0, sizeof(ans));
		int cf = 0;
		maxlen = 0;
		while(cin>>s){
			if(s == "0")	break;
			int len = s.length();
			for(int i=0; i<len; i++){
				ans[i] = ans[i] + s[len-i-1] - '0' + cf;
				cf = ans[i]/10;
				ans[i] %= 10;
			}
			while(cf > 0){
				ans[len] += cf;
				cf = ans[len]/10;
				ans[len] %= 10;
				len++;
			}
			maxlen = max(maxlen, len);
		}
		int k;
		for(k=maxlen; k>=0; k--){
			if(ans[k] != 0)	break;
		}
		if(k == -1)	cout<<0<<endl;
		else{
			for(int i=k; i>=0; i--)	cout<<ans[i];
			cout<<endl;
		}
		
		
		if(t)	cout<<endl;
	}
	
	return 0;
}
