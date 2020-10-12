#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	int n, maxn;
	cin>>n;
	string s, ans;
	while(n != 0){
		maxn = 0;
		map <string,int> a; 
		for(int i=0; i<n; i++){
			cin>>s;
			a[s]++;
			if(a[s] > maxn){
				maxn = a[s];
				ans = s;
			}
		}
		cout<<ans<<endl;
		cin>>n;
	}
	
	return 0;
}
