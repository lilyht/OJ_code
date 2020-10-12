#include <iostream>
using namespace std;
int f[52];

int main(){
	int a, b, n;
	cin>>a>>b>>n;
	while(a!=0 && b!=0 && n!=0){
//		memset(f, 0, sizeof(f));
		f[1] = f[2] = 1;
		int n_ = n<50?n:50;
		for(int i=3; i<=n_; i++){
			f[i] = (a*f[i-1] + b*f[i-2])%7;
		}
		cout<<f[n%49]<<endl;
		cin>>a>>b>>n;
	}
	
	return 0;
}
