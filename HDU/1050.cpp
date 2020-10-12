//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//int n;
//int ans, maxans;
//
//struct node{
//	int l, r;
//	bool flag;
//}a[202];
//
//bool cmp(node x, node y){
//	if(x.r != y.r)	return x.r < y.r;
//	return x.l < y.l;
//}
//
//int main(){
//	int t;
//	cin>>t;
//	while(t--){
//		cin>>n;
//		memset(a, 0, sizeof(a));
//		int s, t;
//		for(int i=0; i<n; i++){
//			cin>>s>>t;
//			s = (s+1)/2;
//			t = (t+1)/2;
//			a[i].l = s;
//			a[i].r = t;
//			if(a[i].l > a[i].r){
//				int temp = a[i].r;
//				a[i].r = a[i].l;
//				a[i].l = temp;
//			}
//		}
//		sort(a, a+n, cmp);
//		for(int i=0; i<n; i++){
//			ans = 10;
//			for(int j=i+1; j<n; j++){
//				if(a[i].r >= a[j].l){
//					ans += 10;
//				}
//			}
//			if(ans > maxans)	maxans = ans;
//		}
//		cout<<maxans<<endl;
//	}
//	
//	return 0;
//}
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int cnt[203];

int main(){
	int t, s, c;
	cin>>c;
	while(c--){
		int n;
		cin>>n;
		int ans = 0;
		memset(cnt, 0, sizeof(cnt));
		for(int i=0; i<n; i++){
			cin>>s>>t;
			if(s > t){
				int temp = t;
				t = s;
				s = temp;
			}
			for(int j=(s+1)/2; j<=(t+1)/2; j++){
				cnt[j]++;
			}
		}
		for(int i=1; i<=200; i++){
			ans = max(ans, cnt[i]);
		}
		cout<<ans*10<<endl;
	}
	
	return 0;
}
