#include <iostream>
using namespace std;
//ÄæÐò¶ÔÊý 
//2020-08-12 08:50:30	Accepted	2689	109MS	1408K	280 B	G++
int a[1005];

int main() {
	int n;
	while(cin>>n) {
		int cnt = 0;
		for(int i=0; i<n; i++)	cin>>a[i];
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(a[i] > a[j]) 
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
