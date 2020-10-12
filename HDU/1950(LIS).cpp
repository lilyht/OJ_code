#include <iostream>
#include <string.h>
using namespace std;
const int INF = 999999999;
//2020-08-19 11:32:00	Accepted	1950	343MS	1708K	512B	G++
//不能使用O(n^2)的动态规划算法，需要用二分查找优化，变为O(nlogn) 
//参考教程：https://blog.csdn.net/wbin233/article/details/77570070

/* 思路： 
 * 可以发现dp数组是单调递增的，
 * 因此对于每一个a[i]，先判断是否可以直接插入到dp数组尾部
 * 即比较其与dp数组的最大值即最后一位；
 * 如果不可以，则找出dp中第一个大于等于a[i]的位置，（查找过程为二分）用a[i]替换之。
 * 这个算法其实已经不是DP了 
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
				//接到后面
				dp[++pos] = a[i];
			}
			else {
				//找到dp中第一个大于等于a[i]的元素下标 
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
