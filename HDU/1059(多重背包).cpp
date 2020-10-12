#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[7];
int c[7];
int w[1000];
int dp[1000010];

int main() {
	int cnt = 0;
	int sum = 0;
	while(1){
		memset(c, 0, sizeof(c));
		sum = 0;
		for(int i=1; i<=6; i++){
			cin>>c[i];
			sum += c[i]*i; 
		}
		for(int i=1; i<=6; i++)
			a[i] = i;
		if(sum == 0)
			break;
		else
			cnt++;
		cout<<"Collection #"<<cnt<<":"<<endl;
		
		if(sum%2 == 1)	cout<<"Can't be divided."<<endl;
		else{
			sum = sum >> 1;
			//分组
			int gn = 0, x;
			for(int i=1; i<=6; i++){
				for(int j=1; c[i]>0; j *= 2){
					x = min(j, c[i]);
					c[i] -= x;
					w[gn++] = a[i]*x;
				}
			}
			//0/1 packge
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			//i从0开始，到组数结束，是固定的 
			for(int i=0; i<gn; i++){
				for(int j=sum; j>=w[i]; j--){
					if(dp[j-w[i]])
						dp[j] = 1;
				}
			}
			if(dp[sum])	cout<<"Can be divided."<<endl;
			else	cout<<"Can't be divided."<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}
