#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
// Humble Numbers

ll dp[5845];

ll min(ll a, ll b, ll c, ll d){
	ll minx = a<b?a:b;
	ll miny = c<d?c:d;
	if(minx < miny)	return minx;
	else	return miny;
}

void init(){
	int i = 1;
	dp[i] = 1;
	int a2 = 1, a3 = 1, a5 = 1, a7 = 1;
	i = 2;
	while(i <= 5842){
		dp[i] = min(dp[a2]*2, dp[a3]*3, dp[a5]*5, dp[a7]*7);
		if(dp[i] == dp[a2]*2)	a2++;
		if(dp[i] == dp[a3]*3)	a3++;
		if(dp[i] == dp[a5]*5)	a5++;
		if(dp[i] == dp[a7]*7)	a7++;
		
		i++;
	}
}

int main(){
	init();
	int n;
	string tag;
	while(cin>>n){
		if(n == 0)	break;
		//ÅÐ¶Ïtag
		if(n>20 || n<10){
			int x = n%10;
			if(x == 1 && n%100 != 11)	tag = "st";
			else if(x == 2 && n%100 != 12)	tag = "nd";
			else if(x == 3 && n%100 != 13)	tag = "rd";
			else	tag = "th";
		}
		else{
			tag = "th";
		}
		cout<<"The "<<n<<tag<<" humble number is "<<dp[n]<<"."<<endl;
	}
	
	return 0;
}
