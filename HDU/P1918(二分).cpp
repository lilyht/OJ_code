#include <iostream>
#include <algorithm>
using namespace std;
//看在这个题的主人公是DL的份上，就做这道题吧

int n;
struct node{
	int num;
	int index;
}a[100005];

bool cmp(node u, node v) {
	return u.num < v.num;
}

int binarysearch(int x) {
	int l = 0;
	int r = n-1;
	while(l <= r) {
//		cout<<l<<" "<<r<<endl;
		int mid = (l + r) >> 1;
		if(a[mid].num == x) {
			cout<<a[mid].index<<endl;
			return 0;
		}
		else if(a[mid].num > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout<<0<<endl;
	return 0;
}

int main() {
	int dl, q, res;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i].num;
		a[i].index = i+1;
	}
	sort(a, a+n, cmp);
	cin>>q;
	for(int i=0; i<q; i++) {
		cin>>dl;
		binarysearch(dl);
	}
	
	return 0;
}
