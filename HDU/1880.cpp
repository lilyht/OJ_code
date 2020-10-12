#include <bits/stdc++.h>
using namespace std;
#define repd(i,x,n) for(int i=x;i<=n;i++)
typedef long long ll;
const int maxn = 300007;
const int inf = 0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
string a[maxn];
// string b[maxn];
const ll p = 6151ll;
const ll mod = 1610612741;
map<ll, int> m;
string s1;

int main() {
	string s2;
	int id = 0;
	while (1) {
		getline(cin, s1);
		if (s1[0] == '@') {
			break;
		}
		s2 = s1.substr(s1.find(']') + 2);
		s1 = s1.substr(0, s1.find(']'));
		s1.erase(s1.begin());
		int len = s1.length();
//		 cout << s1 << endl << s2 << "---"<<endl;
		ll num = 0ll;
		repd(i, 0, len - 1) {
			num = (num * p % mod + s1[i]) % mod;
		}
		// cout << num << " " << s1 << endl;
		a[++id] = s2;
		m[num] = id;

		num = 0ll;
		len = s2.length();
		repd(i, 0, len - 1) {
			num = (num * p % mod + s2[i]) % mod;
		}
		// cout << num << " " << s2 << endl;
		a[++id] = s1;
		m[num] = id;
		// cout<<s1<<" "<<s2<<endl;
	}
	int q;
	// cin >> q;
	scanf("%d", &q);
	string ask;
	getchar();
	while (q--) {
		getline(cin, ask);
		// chu(ask);
		if (ask[0] == '[') {
			int len = ask.length();
			ll num = 0ll;
			repd(i, 1, len - 2) {
				num = (num * p % mod + ask[i]) % mod;
			}
			// cout << num << " " << ask << endl;
			if (m.find(num) == m.end()) {
				cout << "what?" << '\n';
			} else {
				cout << a[m[num]] << "\n";
			}
		} else {
			int len = ask.length();
			ll num = 0ll;
			repd(i, 0, len - 1) {
				num = (num * p % mod + ask[i]) % mod;
			}
			// cout << num << " " << ask << endl;
			if (m.find(num) == m.end()) {
				cout << "what?" << '\n';
			} else {
				cout << a[m[num]] << "\n";
			}
		}
	}
	// cout << endl;
	return 0;
}
