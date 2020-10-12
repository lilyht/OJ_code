#include <iostream>
using namespace std;
//因为n为奇数，且特殊值出现次数大于一半，所以特殊值做为解时cnt不会小于1，所以最终的解一定就是特殊值。

int main(){
	int n, x, ans;
	while(cin>>n){
		int cnt = 0;
		for(int i=0; i<n; ++i){
			cin>>x;
			if(cnt == 0){
				//换数
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
