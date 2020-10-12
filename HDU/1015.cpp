#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int total;
bool flag = false;
char s[30];

int main(){
	int sum;
	string st;
	while(1){
		cin>>sum>>st;
		if(sum == 0 && st == "END")	break;
		int len = st.length();
		//sort
		for(int i=0; i<=len; i++){
			s[i] = st[i];
		}
		sort(s, s+len);
		total = 0;
		flag = false;
		for(int i=len-1; i>=0; --i){
			for(int j=len-1; j>=0; --j){
				if(i != j)
					for(int k=len-1; k>=0; --k){
						if(k != i && k != j)
							for(int h=len-1; h>=0; --h){
								if(h != i && h != j && h != k)
									for(int m=len-1; m>=0; --m){
										if(i != m && j != m && k != m && h != m ){
											total = (s[i] - 'A' + 1) - (s[j] - 'A' + 1)*(s[j] - 'A' + 1)
											 + (s[k] - 'A' + 1)*(s[k] - 'A' + 1)*(s[k] - 'A' + 1)
											 - (s[h] - 'A' + 1)*(s[h] - 'A' + 1)*(s[h] - 'A' + 1)*(s[h] - 'A' + 1)
											 + (s[m] - 'A' + 1)*(s[m] - 'A' + 1)*(s[m] - 'A' + 1)*(s[m] - 'A' + 1)*(s[m] - 'A' + 1);
											if(total == sum){
												cout<<s[i]<<s[j]<<s[k]<<s[h]<<s[m]<<endl;
												flag = 1;
											}
										}
									}
								if(flag)	break;
							}
						if(flag)	break;
					}
				if(flag)	break;
			}
			if(flag)	break;
		}
		if(!flag)	cout<<"no solution"<<endl;
	}
	
	return 0;
} 
