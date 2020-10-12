#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
string a, b;
int sa[1005], sb[1005], ans[1005];
int cnt = 0;

int main(){
	int t;
	cin>>t;
	while(t--){
//		memset(sa, 0, sizeof(sa));
//		memset(sb, 0, sizeof(sb));
//		memset(ans, 0, sizeof(ans));
		for(int i=0; i<1005; i++){
			sa[i] = sb[i] = ans[i] = 0;
		}
		cnt++;
		cin>>a>>b;
		int lena = a.length();
		int lenb = b.length();
		for(int i=0; i<lena; i++)
			sa[i] = a[lena-i-1] - '0';
		for(int i=0; i<lenb; i++)
			sb[i] = b[lenb-i-1] - '0';
		
		int cf = 0;
		int k;
		for(k=0; k<=max(lena, lenb); k++){
			ans[k] = sa[k] + sb[k] + cf;
			cf = ans[k]/10;
			ans[k] %= 10;
		}
		k = k - 1;
		if(ans[k] == 0)	k--;
		cout<<"Case "<<cnt<<":"<<endl;
		cout<<a<<" + "<<b<<" = ";
		for(k; k>=0; k--)	cout<<ans[k];
		cout<<endl;
		if(t != 0){
			cout<<endl;
		}
			
	}
	
	return 0;
}
