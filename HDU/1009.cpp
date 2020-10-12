#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct node{
	double j, f;
	double v;
}a[1000000];

bool cmp(node x, node y){
	return x.v > y.v;
}

int main(){
	double m;
	int n;
	cin>>m>>n;
	double c = 0, ans = 0.0;
	while(m != -1 && n != -1){
		for(int i=1; i<=n; ++i){
			cin>>a[i].j>>a[i].f;
			a[i].v = a[i].j*1.0/a[i].f;
		}
		sort(a+1, a+n+1, cmp);
		c = m;
		ans = 0;
		int k;
		for(k=1; k<=n; ++k){
			if(c >= a[k].f){
				ans += a[k].j;
				c -= a[k].f;
				continue;
			}
			if(c < a[k].f){
				ans += a[k].j/a[k].f*c;
				c = 0;
				break;
			}
		}
		cout<<fixed<<setprecision(3)<<ans<<endl;
		cin>>m>>n;
	}
	
	return 0;
}
