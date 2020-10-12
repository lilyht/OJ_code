#include <iostream>
using namespace std;
//2020-08-22 19:56:18	Accepted	1229	31MS	1392K	344 B	G++
int a, b, k;

int main() {
	while(cin>>a>>b>>k && (a+b)) {
		int x = a;
		int y = b;
		int flag = 1;
		while(k--) {
			if(x%10 != y%10) {
				flag = 0;
				break;
			}
			x = x/10;
			y = y/10;
		}
		if(flag == 1) {
			cout<<-1<<endl;
			continue;
		}
		else {
			cout<<a + b<<endl;
		}
	}
	return 0;
}
