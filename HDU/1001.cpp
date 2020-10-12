#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		if(n&1 == 1)
			cout<<(n+1)/2*n<<endl;
		else
			cout<<n/2*(n+1)<<endl;
		cout<<endl; 
	}
	
	return 0;
}
