#include <bits/stdc++.h>
using namespace std;
//²Î¿¼²©¿Í https://blog.csdn.net/qq_45958683/article/details/107604691 
int main() {
	long long test;
	scanf("%lld", &test);
	while(test--) {
		long long n, m;
		scanf("%lld%lld", &n, &m);
		if(m==0)
			cout<<"0"<<endl;
		else if(m>=n/2)
			cout<<n*(n-1)/2<<endl;
		else {
			long long t = n*m - m*(m+1)/2 + m*(n-2*m) + m*(m-1)/2;
			cout<<t<<endl;
		}
	}
	return 0;
}
