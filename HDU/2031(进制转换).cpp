#include <iostream>
#include <stack>
using namespace std;
//2020-08-21 20:30:16	Accepted	2031	0MS	1400K	506 B	G++
stack<int> s;

int main() {
	int n, r, ans, out;
	while(cin>>n>>r) {
		while(!s.empty())	s.pop();
		if(n == 0) {
			cout<<0<<endl;
			continue;
		}
		int flag = 0;
		if(n < 0) {
			flag = 1;
			n = -n;
			cout<<"-";
		}
		while(n >= 1) {
			ans = n % r;
			s.push(ans);
			n = n / r;
		}
		while(!s.empty()) {
			out = s.top();
			s.pop();
			if(out >= 10)
				cout<<(char)('A' + out - 10);
			else
				cout<<out;
		}
		cout<<endl;
	}
	return 0;
}
