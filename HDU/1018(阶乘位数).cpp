#include <iostream>
#include <cmath>
using namespace std;
//����һ��������a��λ������(int)log10(a) + 1
//�˷�ͨ��logת���ɼӷ� 
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
