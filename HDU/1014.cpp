#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int m, int n){
    return (n == 0) ? m : gcd(n, m % n);
}

int main(){
	int a, b;
	while(cin>>a>>b){
		cout<<setw(10)<<a;
		cout<<setw(10)<<b;
		if(gcd(a, b) == 1)//»¥ÖÊ 
			cout<<"    Good Choice"<<endl;
		else
			cout<<"    Bad Choice"<<endl;
		cout<<endl;
	}
	
	return 0;
}
