#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 5005;

int vis[MAXN];
int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		if(n <= 3) {
			cout<<1;
			for(int i=2; i<=n; i++)
				cout<<" "<<i;
			cout<<endl;
		}
		else {
			memset(vis, 0, sizeof(vis));
			int s = n;
			while(s > 3) {
				for(int i=1, k=1; i<=n; i++) {
					if(k % 2 == 0) {
						if(!vis[i]) {
							vis[i] = 1;
							s--;
							k++;
						}
					}
					else if(!vis[i]) {
						k++;
					}
				}				
				if(s <= 3)	break;
				for(int i=1, k=1; i<=n; i++) {
					if(k % 3 == 0) {
						if(!vis[i]) {
							vis[i] = 1;
							s--;
							k++;
						}
					}
					else if(!vis[i]) {
						k++;
					}
				}
			}
//			cout<<s<<endl;
			cout<<1;
			for(int i=2; i<=n; i++) {
				if(!vis[i])
					cout<<" "<<i;
			}
			cout<<endl;
		}
	}
	
	return 0;
}
