#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 100005;
//2020-09-06 14:19:09	Accepted	3792	967MS	1852K	741 B	G++
int n;
int isp[MAXN];
int primetable[MAXN];
void prime() {
	memset(isp, 0, sizeof(isp));  //isp为0代表是素数，为1代表不是素数 
	isp[0] = isp[1] = 1;
	int cnt = 0;
	for(int i=2; i<=100005; i++) {
		if(isp[i] == 0) {  //是素数 
			primetable[cnt] = i;
			cnt++; 
			for(int j=i+i; j<=100005; j+=i) {
				isp[j] = 1;
			}
		}
	}
//	for(int i=0; i<cnt; i++)
//		cout<<primetable[i]<<" ";
}

int main() {
//	2, 3, 5, 7, 11, 13, 17, 19
	prime();
	
	while(cin>>n && n>0) {
		int ans = 0;
		for(int i=1; i<n; i++) {
			if(primetable[i] > n)
				break;
			else {
				if(primetable[i] - primetable[i-1] == 2)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
