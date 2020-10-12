#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n = 2, a = 2;
	double res = 2.5;
	cout<<"n e\n- -----------\n";
	cout<<"0 1\n1 2\n2 2.5\n";
	while(n < 9){
		n++;
		a = n*a;
		res += 1.0/a;
		cout<<fixed<<setprecision(9)<<n<<" "<<res<<endl;
	}
	
	return 0;
}
