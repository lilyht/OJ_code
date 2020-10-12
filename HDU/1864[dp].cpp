#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

/*
 * 最大报销额
 * 现有一笔经费可以报销一定额度的发票。允许报销的发票类型包括买图书（A类）、文具（B类）、差旅（C类）
 * 要求每张发票的总额不得超过1000元，每张发票上，单项物品的价值不得超过600元。
 * 现请你编写程序，在给出的一堆发票中找出可以报销的、不超过给定额度的最大报销额。 
 */
int check[35];
int dp[3000050];  //因为dp数组的下标必须是整数，而输入的价格为两位小数，所以扩大100倍变整数，最后输出的时候再变回去  30 * 1000 * 100 

int main() {
	
	double Q = 0.0;
	while(cin>>Q) {
		int N = 0;
		cin>>N;
		memset(check, 0, sizeof(check));
		memset(dp, 0, sizeof(dp));
		int index = 0;
		if(N == 0) {
			break;
		}
		for(int i=0; i<N; i++) {
			int m;
			cin>>m;
			if(m != 0) {
				double a = 0.0, b = 0.0, c = 0.0;
				double aprice = 0.0, bprice = 0.0, cprice = 0.0;
				bool flag = 1;
				double total = 0.0;
				for(int j=0; j<m; j++) {
					char type, colon;
	                double price = 0.0;
					cin>>type>>colon>>price;
					if(type == 'A') {
						aprice += price;
					}
					else if (type == 'B') {
						bprice += price;
					}
					else if (type == 'C') {
						cprice += price;
					}
					else {
						flag = 0;
					}
					total += price;
				}
				
				if(aprice > 600.0 || bprice > 600.0 || cprice > 600.0 ) flag = 0;
				if(total > 1000.0)	flag = 0;
				
				if(flag == 1) {
					//有效发票
					check[index] = (int)(total * 100);
					index++ ;
				}
			}
		}
		
		dp[0] = 0;
		int intQ = (int)(Q * 100);
		for(int i=0; i<index; i++) {
			for(int j=intQ; j>=check[i]; j--) {
				dp[j] = max(dp[j], dp[j-check[i]] + check[i]);
			}
		}
		cout<<fixed<<setprecision(2);  // 固定输出两位小数，所有后面的输出均可以这种格式输出 
		cout<<dp[intQ] * 1.0 / 100<<endl;
	}

	return 0;
}
