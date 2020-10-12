#include <iostream>
using namespace std;
//2020-09-16 23:35:29	Accepted	5747	483MS	1412K	463 B	G++ 
int pow(int a, int b) {  //a^b 
	int ans = 1;
	while(b) {
		if(b&1)	ans *= a;
		a *= a;
		b = b >> 1; 
	}
	return ans;
}

int main() {
	int n, m, t;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		int sum = 0;
		m = min(m, 30);  //不加这句话，会溢出，mi等于0，出现CE 
		for(int i=m; i>=0; i--) {  //2^30 > 10^9
			int mi = pow(2, i);
			sum += n / mi;
			n = n % mi;
			if(n == 0)
				break;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
