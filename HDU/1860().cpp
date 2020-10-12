#include <iostream>
#include <string>
using namespace std;
//2020-08-23 16:08:32	Accepted	1860	0MS	1396K	476 B	G++
int ans[8];
string s, t;
int main() {
	s = "";
	while(getline(cin, s) && s != "#") {
		//getchar();  //之前加了getchar()就一直WA 
		getline(cin, t);
		int lens = s.length();
		int lent = t.length();		
		for(int i=0; i<lens; i++) {
			int cnt = 0;
			for(int j=0; j<lent; j++) {
				if(s[i] == t[j])
					cnt++;
			}
			ans[i] = cnt;
		}
		for(int i=0; i<lens; i++) {
			cout<<s[i]<<" "<<ans[i]<<endl;
		}
	}
	return 0;
}
