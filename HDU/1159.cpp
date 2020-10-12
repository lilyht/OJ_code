#include <iostream>
using namespace std;
const int MAXM = 100010;

int l[MAXM];
int C[MAXM]; 
int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++)	cin>>l[i];
	//·Ö×é
	int index = 0;
	for(int i=0; i<m; i++) {
		int x = n;
		int r = 1;
		while(x > r) {
			x -= r;
			C[++index] = r * l[i];
			r = r << 1;
		}
		if(x > 0) {
			C[++index] = x * l[i];
		}
	}
	//01±³°ü 
	for(int i=0; i<=index; i++)
		cout<<C[i]<<" ";
	cout<<endl;
	//dp
	for(int i=0; i<index; i++) {
		for(int j=n; j>=C[i]; j--) {
			
		}
	}
	
	return 0;
}
