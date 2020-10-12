#include <iostream>
#include <iomanip>
using namespace std;
double a, b, c, k, p;

double F(double i, double j){
	return a*(j*j*j - i*i*i)/3 + (b-k)*(j*j-i*i)/2 + (c-p)*(j-i);
}

int main(){
	double x1, x2, x3, y1, y2, y3;
	int t;
	cin>>t;
	while(t--){
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		a = (y3-y1)/((x3-x1)*(x3-x1));
		b = -2*a*x1;
		c = y1 - a*x1*x1 - b*x1;
		k = (y3-y2)/(x3-x2);
		p = y2 - k*x2;
//		cout<<a<<" "<<b<<" "<<c<<endl;
//		cout<<k<<" "<<p<<endl;
		cout<<fixed<<setprecision(2)<<F(x2, x3)<<endl;
	}
	
	
	return 0;
}
