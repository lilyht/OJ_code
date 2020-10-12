#include <bits/stdc++.h>
using namespace std;
//参考 https://www.cnblogs.com/agenthtb/p/7338105.html 
//2020-08-17 10:35:37	Accepted	6092	343MS	7340K	1086 B	G++
typedef long long ll;
const int maxn = 5e5+500;
int n,m;
ll cnt[maxn];  //input 
ll sum[maxn];
int num[maxn];

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		memset(sum,0,sizeof sum);
		memset(num,0,sizeof num);
		scanf("%d%d", &n, &m);
		for (int i=0; i<=m; ++i)
			scanf("%lld", &cnt[i]);
		num[0] = 0;
		sum[0] = cnt[0];  // sum[i]表示求到当前位置之前子集和为i的子集个数 
		//因为 2^num[0]=cnt[0] ，所以可以第一个求出0的个数 
		while((1<<num[0]) < cnt[0])	num[0]++;
		
		//思路 
		//num[i]*sum[0]+sum[i]=cnt[i],也就是说一共和为i的子集个数等于集合中数字i的个数乘和为0的子集个数再加上之前那些由>0&&<i的元素构成的子集中和为i的个数
		//然后我们每次求出一个num[i]后,用完全背包的思想将这num[i]个i,一个一个的加入到集合中,用完全背包的思想更新sum数组
		for(int i=1; i<=m; ++i) {
			num[i] = (cnt[i] - sum[i]) / sum[0];  //num[i]*sum[0]+sum[i]=cnt[i]
			for(int j=1; j<=num[i]; ++j) {  //一个一个的加入几个
				for(int k=m; k>=i; --k) {  //完全背包思想更新 sum
					sum[k] += sum[k-i];
				}
			}
		}
		vector<int> vec;
		for(int i=0; i<=m; ++i) {
			for(int j=0; j<num[i]; ++j)
				vec.push_back(i);
		}
		for (int i=0; i<vec.size(); ++i)
			printf("%d%c", vec[i], i==(vec.size()-1) ? '\n' : ' ');
	}
	return 0;
}
