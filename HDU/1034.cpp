#include <iostream>
using namespace std;
int cnt, k;
int a[1000000];

int main(){
	int n;
	while(cin>>n){
		if(n == 0)	break;
		for(int i=0; i<n; i++)	cin>>a[i];
		cnt = 0;
		while(1){
			for(k=1; k<n; k++){
				if(a[k] != a[k-1])	break;
			}
			if(k == n)	break;
			cnt++;
			int out = a[n-1]/2;
			for(int i=n-1; i>0; i--){
				a[i] /= 2;
				a[i] = a[i] + a[i-1]/2;
			}
			a[0] = a[0]/2 + out;
			for(int i=0; i<n; i++){
				if(a[i]&1)	a[i]++;
			}
		}
		cout<<cnt<<" "<<a[0]<<endl;
	}
	
	return 0;
}
