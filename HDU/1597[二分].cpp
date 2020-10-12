#include <iostream>
#include <string.h> 
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[66000];

int main() {
	
	a[0] = 0;
	int i;
	for(i=1; a[i-1] + i < pow(2, 31); i++) {
		a[i] = a[i-1] + i;
	}
	
	int k, n, index;
	cin>>k;
	for(int j=0; j<k; j++) {
		cin>>n;
		index = lower_bound(a+1, a+i, n) - a;
		//函数lower_bound()在first和last中的前闭后开区间，进行二分查找。返回从first开始的第一个大于或等于val的元素的地址。
		index = (n - a[index-1]) % 9;
		if(index != 0)
			cout<<index<<endl;
		else
			cout<<9<<endl;
	}
	return 0;
} 
