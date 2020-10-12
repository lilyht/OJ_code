#include <iostream>
using namespace std;
//2020-09-08 21:46:29	Accepted	2097	31MS	1404K	496B	G++	
int getSum(int x, int L) {
	int sum = 0;
	while(x > 0) {
		sum += x % L;
		x = x / L;
	}
	return sum;
}

int main() {
	int n;
	while(cin>>n && n) {
		int decsum = getSum(n, 10);
		int sum1 = getSum(n, 16);
		if(decsum != sum1) {
			cout<<n<<" is not a Sky Number."<<endl;
			continue;
		}
		int sum2 = getSum(n, 12);
		if(decsum != sum2) {
			cout<<n<<" is not a Sky Number."<<endl;
			continue;
		}
		cout<<n<<" is a Sky Number."<<endl;
	} 
	return 0;
}
