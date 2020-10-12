#include <iostream>
using namespace std;

int main(){
	//O(tlogn)
	int t, n, ans = 1;
	long long x;
	cin>>t;
	while(t--){
		cin>>x;
		n = x;
		x %= 10;
		ans = 1;
		while(n){
			if(n&1)
				ans = (ans*x)%10;
			x = (x*x)%10;
			n = n >> 1;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
