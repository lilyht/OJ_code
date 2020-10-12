#include <iostream>
using namespace std;
//Ã°ÅÝÅÅÐò£¬O(n^2) 
//2020-08-12 08:50:04	Accepted	2689	93MS	1408K	371 B	G++	
int a[1005];

int main() {
	int n;
	while(cin>>n) {
		int cnt = 0;
		for(int i=0; i<n; i++)	cin>>a[i];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n-i-1; j++) {
				if(a[j] > a[j+1]) {
					int tmp = a[j+1];
					a[j+1] = a[j];
					a[j] = tmp;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
