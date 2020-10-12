#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//2020-08-22 16:03:27	Accepted	1234	46MS	1608K	471 B	G++
struct rec{
	string id;
	string beg;
	string end;
}a[1005];

bool cmp1(rec x, rec y) {
	return x.beg < y.beg; 
}

bool cmp2(rec x, rec y) {
	return x.end > y.end; 
}

int main() {
	int n, t;
	cin>>n;
	while(n--) {
		cin>>t;
		for(int i=0; i<t; i++)
			cin>>a[i].id>>a[i].beg>>a[i].end;
		sort(a, a+t, cmp1);
		cout<<a[0].id<<" ";
		sort(a, a+t, cmp2);
		cout<<a[0].id<<endl;
	}
	return 0;
}
