#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 205;
//2020-08-30 13:19:41	Accepted	1200	0MS	1396K	479 B	G++
//����1.strlen()�÷�  2.reverse()�÷�  3.˼· 
char st[MAXN];
int main() {
	int c;
	while(cin>>c && c) {
		cin>>st;
		int len = strlen(st);
		int r = len / c;
		
		for(int i=0; i<r; i++) {
			if(i&1) {
				//��������ת��ȥ
				reverse(st+c*i, st+c*(i+1));
			} 
		}
//		cout<<st<<endl;
		for(int i=0; i<c; i++) {
			for(int j=0; j<r; j++) {
				cout<<st[i+j*c];
			}
		}		
		cout<<endl;
	} 
	return 0;
}
