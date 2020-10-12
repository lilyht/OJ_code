#include <iostream>
using namespace std;

int n, m;

int gcd(int x, int y) {
//	if(y > 0)  //上面这种写法不对，为什么呀 
//		gcd(y, x%y);
//	return x;
	if(y == 0)	return x;
	return gcd(y, x%y);
}

int main() {
	int p;
	cin>>p;
	while(p--) {
		cin>>m>>n;
		//最大公约数是1，则不存在safe holes
		int res = gcd(m, n);
		if(res == 1)	cout<<"NO"<<endl;
		else	cout<<"YES"<<endl;
	}
	
	return 0;
}
