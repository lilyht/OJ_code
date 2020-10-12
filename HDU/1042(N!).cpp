#include <iostream>
#include <cstring>
using namespace std;
int a[40000];
int len = 1;

int main(){
	int n;
	while(cin>>n){
		memset(a, 0, sizeof(a));
		a[0] = 1;
		len = 1;
		int cf = 0;
		for(int i=2; i<=n; i++){
			//ÿλ
			int j = 0;
			for(j=0; j<len; j++){
				a[j] = a[j]* i + cf ;
				cf = a[j]/10;
				a[j] = a[j]%10;
			} 
			while(cf){
				a[j++] = cf % 10;
				cf /= 10;
			}
			int k;
			for(k=39999; k>=0; k--){
				if(a[k] != 0)	break;
			}
			len = k + 1;
		}
		for(int c=len-1; c>=0; c--){
			cout<<a[c];
		}
		cout<<endl;
	}
	
	return 0;
}
