#include <iostream>
#include <algorithm>
using namespace std;
int ans = 0;
int len = 1;

int num(int x){
	if(x == 1)	return len;
	else{
		if(x&1 == 1){
			len++;
			num(3*x + 1);
		}
		else{
			len++;
			num(x>>1);
		}
	}
}

int main(){
	int a, b;
	while(cin>>a>>b){
		ans = 0;
		cout<<a<<" "<<b<<" ";
		if(a > b){
			int temp = a;
			temp = a;
			a = b;
			b = temp;
		}
		for(int i=a; i<=b; i++){
			len = 1;
			ans = max(ans, num(i));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
