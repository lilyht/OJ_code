#include <iostream>
#include <cmath>
using namespace std;
//任意一个正整数a的位数等于(int)log10(a) + 1
//乘法通过log转化成加法 
int main(){
	int n, x;
	double len;
	cin>>n;
	while(n--){
		cin>>x;
		len = 1;
		for(int i=2; i<=x; i++)
			len += log10(i);
		cout<<(int)len<<endl;
	} 
	
	return 0;
}
