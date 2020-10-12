#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//田忌赛马 
int t[1005], k[1005];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	int n;
	while(cin>>n){
		if(n == 0)	break;
		memset(t, 0, sizeof(t));
		memset(k, 0, sizeof(k));
		int win = 0, fail = 0;
		for(int i=0; i<n; i++)	cin>>t[i];
		for(int i=0; i<n; i++)	cin>>k[i];
		sort(t, t+n, cmp);
		sort(k, k+n, cmp);
		int ts = 0, te = n-1;
		int ks = 0, ke = n-1;
		while(ts <= te){
			if(t[ts] > k[ks]){
				win++;
				ts++;
				ks++;
			}
			else if(t[ts] < k[ks]){
				fail++;
				te--;
				ks++;
			}
			else{
				if(t[te] > k[ke]){
					win++;
					te--;
					ke--;
				}
				else if(t[te] < k[ke]){
					fail++;
					te--;
					ks++;
				}
				else{
					if(t[te] < k[ks]){
						fail++;
						te--;
						ks++;
					}
					else{
						break;  //不好想 
					}
				}
			}
		}
		cout<<200*(win-fail)<<endl;
	}
	
	
	return 0;
}
