#include <iostream>
using namespace std;
typedef long long ll;
//2020-09-02 17:06:44	Accepted	1205	1669MS	1404K	373 B	G++
int main() {
	int t, n;
	ll a;
	cin>>t;
	while(t--) {
		cin>>n;
		ll sum = 0;
		ll maxa = 0;
		for(int i=0; i<n; i++) {
			cin>>a;
			if(a > maxa)
				maxa = a;  //��¼��������һ���ǹ� 
			sum += a;  //��¼�ܺ� 
		}
		//maxa - (sum - maxa) >= 2���볲ԭ�� 
		if(maxa - sum + maxa >= 2)
			printf("No\n");
		else
			printf("Yes\n");
	} 
	return 0;
} 
