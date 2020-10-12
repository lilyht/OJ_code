#include <cstdio>
#include <string.h>
using namespace std;
int cnt = 0, len = 1;
int dp[1000002];
int a[100002];
//最长上升子序列 （加二分优化） 

int main() {
	int n;
	//是while(~scanf("%d", &n))， 注意有 ~ 符号 
	while(~scanf("%d", &n)) {
		memset(a, 0, sizeof(a));
		long long len = 1;
		cnt++;
		int poor, rich;
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &poor, &rich);
			a[poor] = rich;
		}
		dp[1] = a[1];
		//***important***
		//最长递增子序列LIS
		//参考博客：https://blog.csdn.net/u012505432/article/details/52228945?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param 
		for(int i=2; i<=n; i++) {
			long long l = 0, mid, r = len;
			while(l <= r) {
				mid = (l + r) >> 1;
				if(dp[mid] >= a[i])
					r = mid - 1;
				else
					l = mid + 1;
			}
			dp[l] = a[i];
			if(l > len)	len++;
		}
		//test
		for(int i=1; i<=n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		for(int i=1; i<=n; i++) {
			printf("%d ", dp[i]);
		} 
		
		printf("Case %d:\n", cnt);
		if(len == 1)
			printf("My king, at most 1 road can be built.\n\n");
		else
			printf("My king, at most %d roads can be built.\n\n", len);
	}
	
	return 0;
} 
