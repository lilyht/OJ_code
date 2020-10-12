#include <iostream>
#include <iomanip>
using namespace std;
/*规律：
* 当n，m不全为奇数的时候，最短路径就是n*m；
* 当n，m全为奇数的时候，必然要走一条斜线，就多走了0.41（即根号2），最短路径即为：n*m+0.41.
*/
double sum = 0;

int main(){
	int t, a, b;
	cin>>t;
	int cnt = 0;
	while(t--){
		sum = 0;
		cin>>a>>b;
		if((a&1) == 0 || (b&1) == 0){
			sum = a*b + 0.0;
		}
		else{
			sum = a*b + 0.41;
		}
		cnt++;
		cout<<"Scenario #"<<cnt<<":"<<endl;
		cout<<fixed<<setprecision(2)<<sum<<endl;
		cout<<endl;
	}
	
	return 0;
}
