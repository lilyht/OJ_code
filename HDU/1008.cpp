#include <iostream>
//#include <string.h>
using namespace std;
int a[1000000] = {0};

int main(){
	int n, cost;
	cin>>n;
	while(n != 0){
		cost = 0;
//		memset(a, 0, sizeof(a));
		for(int i=1; i<=n; i++){
			cin>>a[i];
			if(a[i-1] - a[i] > 0)	cost += (a[i-1] - a[i])*4 + 5;
			else	cost += (a[i] - a[i-1])*6 + 5;
		}
		cout<<cost<<endl;
		
		cin>>n;
	}
	
	return 0;
}
