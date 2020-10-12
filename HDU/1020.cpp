#include <iostream>
#include <string>
using namespace std;
string s;
int cnt;

int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>s;
		int len = s.length();
		cnt = 1;
		for(int i=1; i<len; i++){
			if(i != len - 1){
				if(s[i] == s[i-1])	cnt++;
				else{
					if(cnt == 1)	cout<<s[i-1];
					else{
						cout<<cnt<<s[i-1];
						cnt = 1;
					}
				}
			}
			else{
				if(s[i] == s[i-1])	cnt++;
				if(cnt == 1)	cout<<s[i-1]<<s[i];
				else
					cout<<cnt<<s[i-1];
			}
			
		}
		cout<<endl;
	}
	
	return 0;
}
