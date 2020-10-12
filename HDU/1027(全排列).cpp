#include <iostream> 
#include <algorithm>
using namespace std;

int n, m;
int a[1005];

int main() {
	while(cin>>n>>m) {
		for(int i=0; i<n; i++)	a[i] = i+1;
		for(int i=0; i<m-1; i++)
			next_permutation(a,a+n);
		for(int i=0; i<n-1; i++)
			cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	}
	
	return 0;
}
