#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1002];

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++)	cin>>a[i];
		sort(a, a+n);
		for(int i=0; i<n-1; i++)	cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	}
	
	return 0;
}
