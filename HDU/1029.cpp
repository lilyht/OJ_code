#include <iostream>
using namespace std;
//��ΪnΪ������������ֵ���ִ�������һ�룬��������ֵ��Ϊ��ʱcnt����С��1���������յĽ�һ����������ֵ��

int main(){
	int n, x, ans;
	while(cin>>n){
		int cnt = 0;
		for(int i=0; i<n; ++i){
			cin>>x;
			if(cnt == 0){
				//����
				ans = x;
				cnt++;
			}
			else{
				if(x == ans)	cnt++;
				else	cnt--;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
