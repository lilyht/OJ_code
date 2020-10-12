#include <iostream>
using namespace std;
//2020-08-11 21:40:22	Accepted	1098	31MS	1412K	272 B	G++
//参考 http://acm.hdu.edu.cn/discuss/problem/post/reply.php?action=support&postid=23567&messageid=1&deep=0 
int k;
int main() {
	while(cin>>k) {
		int a = 0;
		//存在a使得 (18+ka)%65 == 0 即可 
		for(a=1; a<=65; a++) {
			if((18+k*a) % 65 == 0) {
				cout<<a<<endl;
				break;
			}
		}
		if(a >= 66)
			cout<<"no"<<endl;
	}
	return 0;
} 
