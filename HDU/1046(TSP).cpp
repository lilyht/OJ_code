#include <iostream>
#include <iomanip>
using namespace std;
/*���ɣ�
* ��n��m��ȫΪ������ʱ�����·������n*m��
* ��n��mȫΪ������ʱ�򣬱�ȻҪ��һ��б�ߣ��Ͷ�����0.41��������2�������·����Ϊ��n*m+0.41.
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
