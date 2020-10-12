#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
//2020-09-14 10:07:19	Accepted	6744	15MS	1696K	738 B	G++
int a[11] = {95, 90, 85, 80, 75, 70, 67, 65, 62, 60, 0};
double b[11] = {4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.0, 0.0};
double dp[405];

void err() {
	//这种做法在x=360的时候答案是15.9，而正确答案应为16.0 
	int x;
	cin>>x;
	double sum = 0.0;
	for(int j=0; j<10; j++) {
		while(x >= a[j]) {
			x -= a[j];
			sum += b[j];
		}
	}
	cout<<fixed<<setprecision(1)<<sum<<endl;
} 


int main() {
	int t, x;
	cin>>t;
	//完全背包 
	while(t--) {
		cin>>x;
		memset(dp, 0.0, sizeof(dp));
		for(int i=0; i<10; i++) {
			for(int j=a[i]; j<=x; j++) {
				dp[j] = max(dp[j], dp[j-a[i]] + b[i]);
			}
		}
		cout<<fixed<<setprecision(1)<<dp[x]<<endl;
	} 
	return 0;
} 
