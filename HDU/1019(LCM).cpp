#include <iostream>
using namespace std;
// LCM 
//typedef long long ll;
//int a[1000];

int gcd(int a, int b){
	if(a%b == 0)	return b;
	else	return gcd(b, a%b); 
}

int LCM(int a, int b){
	return a/gcd(a, b)*b;
	//公式原为 a*b/gcd(a, b)， 但是乘法可能会溢出，所以先除 
}

int main(){
	int t, n, x, lcm;
	cin>>t;
	while(t--){
		cin>>n;
		lcm = 1;
		for(int i=1; i<=n; i++){
			cin>>x;
			lcm = LCM(x, lcm);
		}
		cout<<lcm<<endl;
	}
	
	return 0;
}
