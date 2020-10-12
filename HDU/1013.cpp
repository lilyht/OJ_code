#include <iostream>
#include <string>
using namespace std;
int ans;

int main(){
	string s;
	while(1){
		ans = 0;
		cin>>s;
		if(s == "0")	break;
		int len = s.length();
		for(int i=0; i<len; i++){
			ans += s[i] - '0';
			if(ans > 9){
				ans = ans/10 + ans%10;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
