#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
stack<int> s;
//2020-08-21 21:19:43	Accepted	1877	62MS	1432K	505 B	G++	
int main() {
	ll a, b, ans;
	int r;
	while(cin>>r) {
		if(r == 0)	break;
		cin>>a>>b;
		a = a + b;
		if(a == 0) {
			cout<<0<<endl;
			continue;
		}
		while(!s.empty())	s.pop();
		while(a > 0) {
			ans = a % r;
			s.push(ans);
			a = a / r;
		}
		while(!s.empty()) {
			ans = s.top();
			s.pop();
			if(ans >= 10)
				cout<<(char)('A' + ans - 10);
			else
				cout<<ans;
		}
		cout<<endl;
	}
	
	 
	return 0;
} 
