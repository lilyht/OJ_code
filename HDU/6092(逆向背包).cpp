#include <bits/stdc++.h>
using namespace std;
//�ο� https://www.cnblogs.com/agenthtb/p/7338105.html 
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
		sum[0] = cnt[0];  // sum[i]��ʾ�󵽵�ǰλ��֮ǰ�Ӽ���Ϊi���Ӽ����� 
		//��Ϊ 2^num[0]=cnt[0] �����Կ��Ե�һ�����0�ĸ��� 
		while((1<<num[0]) < cnt[0])	num[0]++;
		
		//˼· 
		//num[i]*sum[0]+sum[i]=cnt[i],Ҳ����˵һ����Ϊi���Ӽ��������ڼ���������i�ĸ����˺�Ϊ0���Ӽ������ټ���֮ǰ��Щ��>0&&<i��Ԫ�ع��ɵ��Ӽ��к�Ϊi�ĸ���
		//Ȼ������ÿ�����һ��num[i]��,����ȫ������˼�뽫��num[i]��i,һ��һ���ļ��뵽������,����ȫ������˼�����sum����
		for(int i=1; i<=m; ++i) {
			num[i] = (cnt[i] - sum[i]) / sum[0];  //num[i]*sum[0]+sum[i]=cnt[i]
			for(int j=1; j<=num[i]; ++j) {  //һ��һ���ļ��뼸��
				for(int k=m; k>=i; --k) {  //��ȫ����˼����� sum
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
