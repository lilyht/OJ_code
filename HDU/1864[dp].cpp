#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

/*
 * �������
 * ����һ�ʾ��ѿ��Ա���һ����ȵķ�Ʊ���������ķ�Ʊ���Ͱ�����ͼ�飨A�ࣩ���ľߣ�B�ࣩ�����ã�C�ࣩ
 * Ҫ��ÿ�ŷ�Ʊ���ܶ�ó���1000Ԫ��ÿ�ŷ�Ʊ�ϣ�������Ʒ�ļ�ֵ���ó���600Ԫ��
 * �������д�����ڸ�����һ�ѷ�Ʊ���ҳ����Ա����ġ�������������ȵ������� 
 */
int check[35];
int dp[3000050];  //��Ϊdp������±������������������ļ۸�Ϊ��λС������������100������������������ʱ���ٱ��ȥ  30 * 1000 * 100 

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
					//��Ч��Ʊ
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
		cout<<fixed<<setprecision(2);  // �̶������λС�������к����������������ָ�ʽ��� 
		cout<<dp[intQ] * 1.0 / 100<<endl;
	}

	return 0;
}
