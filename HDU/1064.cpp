#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double x, sum = 0;
	for(int i=0; i<12; i++){
		cin>>x;
		sum += x;
	}
	cout<<"$"<<fixed<<setprecision(2)<<sum/12<<endl;
	
	return 0;
}
