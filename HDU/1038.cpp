#include <iostream>
#include <iomanip>
#define pi 3.1415927
using namespace std;
double d, t, dis, v;
int r, cnt;

int main(){
	while(cin>>d>>r>>t){
		if(r == 0)	break;
		cnt++;
		dis = d * pi * r / 12 / 5280;
		v = dis / t * 3600;
		cout<<"Trip #"<<cnt<<": ";
		cout<<fixed<<setprecision(2)<<dis<<" "<<v<<endl;
	}
	
	return 0;
}
