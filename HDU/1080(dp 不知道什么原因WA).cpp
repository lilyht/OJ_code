#include <iostream>
#include <cstring>
using namespace std;

//这个题，蜜汁过不去，WA
//这个链接试过，可以过 https://blog.nowcoder.net/n/317b0fcad9be4bb98816c18bc8fc0a4b ，但是明明我们写的是一样的啊，奇了怪了 

const int INF = 0x3f3f3f3f;
int dp[105][105];
char a[105], b[105];
int t;
//string a, b;

int getscore(char x, char y) {
//	cout<<x<<" "<<y<<endl;
	if(x == y && y != '-')	return 5;
	if((x == 'A' && y == 'C') || (y == 'A' && x == 'C'))	return -1;
    if((x == 'A' && y == 'G') || (y == 'A' && x == 'G'))	return -2;
    if((x == 'A' && y == 'T') || (y == 'A' && x == 'T'))	return -1;
    if((x == 'A' && y == '-') || (y == 'A' && x == '-'))	return -3;
    if((x == 'C' && y == 'G') || (y == 'C' && x == 'G'))	return -3;
    if((x == 'C' && y == 'T') || (y == 'C' && x == 'T'))	return -2;
    if((x == 'C' && y == '-') || (y == 'C' && x == '-'))	return -4;
    if((x == 'G' && y == 'T') || (y == 'G' && x == 'T'))	return -2;
    if((x == 'G' && y == '-') || (y == 'G' && x == '-'))	return -2;
    if((x == 'T' && y == '-') || (y == 'T' && x == '-'))	return -1;
    if(x == '-' && y == '-')	return -INF;
}

int main() {
	cin>>t;
	while(t--) {
		int lena, lenb;
//		cin>>lena>>a>>lenb>>b;
		scanf("%d%s%d%s", &lena, a+1, &lenb, b+1);
		
//		a = '0' + a;
//		b = '0' + b;
//		cout<<a<<b;
		for(int i = 0; i<=lena; i++)
            for(int j = 0; j<=lenb; j++)
				dp[i][j] = -INF;
        dp[0][0] = 0;
        
		for(int i=1; i<=lena; i++) 
			dp[i][0] = dp[i-1][0] + getscore(a[i], '-');
		for(int i=1; i<=lenb; i++) 
			dp[0][i] = dp[0][i-1] + getscore(b[i], '-');
		
		for(int i=1; i<=lena; i++) {
			for(int j=1; j<=lenb; j++) {
//				cout<<"*a[i]: "<<a[i]<<" b[i]: "<<b[i]<<endl;
				dp[i][j] = max(dp[i-1][j-1] + getscore(a[i], b[j]), dp[i-1][j] + getscore(a[i], '-'));
				dp[i][j] = max(dp[i][j], dp[i][j-1] + getscore(b[i], '-'));	
				//注意：dp+后面这项之前写反了错了，千万注意别写差！！！ 
			}
		}
//		cout<<dp[lena][lenb]<<endl;
		printf("%d\n", dp[lena][lenb]);
	}
	
	return 0;
} 
