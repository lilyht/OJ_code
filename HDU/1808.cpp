#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
//2020-09-02 19:42:27	Accepted	1808	343MS	2996K	634 B	G++
ll a[MAXN];
ll nest[MAXN];
int main() {
	std::ios::sync_with_stdio(false);  //cin����̫���ˣ����³�ʱ 
	int c, n;
	while(cin>>c>>n && c+n) {
		//init
		for(ll i=0; i<=n; i++)	nest[i] = 0;
		for(ll i=1; i<=n; i++)	cin>>a[i];
		ll sum = 0;  //ǰ׺�� 
		for(ll i=1; i<=n; i++) {
			sum += a[i];
			ll t = sum % c;
			if(t == 0) {
				for(ll j=1; j<i; j++)
					cout<<j<<" ";
				cout<<i<<endl;
				break;
			}
			else if(nest[t]) {
				//����������ֹ�
				for(ll j=nest[t]+1; j<i; j++)
					cout<<j<<" ";
				cout<<i<<endl;
				break;
			}
			nest[t] = i;
		}
	}
	return 0;
}
