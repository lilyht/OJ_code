#include <iostream>
#include <string.h>
using namespace std;
const int INF = 999999999;
//2020-08-19 11:32:00	Accepted	1950	343MS	1708K	512B	G++
//����ʹ��O(n^2)�Ķ�̬�滮�㷨����Ҫ�ö��ֲ����Ż�����ΪO(nlogn) 
//�ο��̳̣�https://blog.csdn.net/wbin233/article/details/77570070

/* ˼·�� 
 * ���Է���dp�����ǵ��������ģ�
 * ��˶���ÿһ��a[i]�����ж��Ƿ����ֱ�Ӳ��뵽dp����β��
 * ���Ƚ�����dp��������ֵ�����һλ��
 * ��������ԣ����ҳ�dp�е�һ�����ڵ���a[i]��λ�ã������ҹ���Ϊ���֣���a[i]�滻֮��
 * ����㷨��ʵ�Ѿ�����DP�� 
 */ 
 
int a[40005], dp[40005];

int main() {
	int n, p;
	cin>>n;
	while(n--) {
		cin>>p;
		for(int i=0; i<p; i++) {
			cin>>a[i];
			dp[i] = INF;
		}
		int pos = 0;
		dp[0] = a[0];
		
		for(int i=1; i<p; i++) {
			if(a[i] > dp[pos]) {
				//�ӵ�����
				dp[++pos] = a[i];
			}
			else {
				//�ҵ�dp�е�һ�����ڵ���a[i]��Ԫ���±� 
				dp[lower_bound(dp, dp+pos+1, a[i]) - dp] = a[i];
			}
		}
		cout<<pos+1<<endl;
	}
	return 0;
}
/*
4
6
4 2 6 3 1 5

10
2 3 4 5 6 7 8 9 10 1

8
8 7 6 5 4 3 2 1

9
5 8 9 2 3 1 7 4 6

*/
