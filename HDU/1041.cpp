//f[n]=f[n-1]+2*f[n-2]
#include <iostream>
using namespace std;
int f[1002][500];
int len;

void cal(){
	len = 1;
	for(int i=3; i<=1001; i++){
		int cf = 0;
		for(int j=0; j<len; j++){
			f[i][j] = f[i][j] + f[i-1][j] + 2*f[i-2][j] + cf;
			if(f[i][len-1] > 9)
				len++;
			cf = f[i][j]/10;
			f[i][j] %= 10;
		}
	}
}

int main(){
	int n;
	f[1][0] = 0;
	f[2][0] = 1;
	cal();
	while(cin>>n){
		if(n == 1){
			cout<<0<<endl;
		}
		else if(n == 2 || n == 3){
			cout<<1<<endl;
		}
		else{
			int k;
			for(k=len; f[n][k] == 0; k--);
			for(int i=k; i>=0; i--)
				cout<<f[n][i];
			cout<<endl;
		}
	}
	
	return 0;
} 
