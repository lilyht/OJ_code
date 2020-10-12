#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N], b[N];
int n, k;
ll m;
//ȷ�������������m�Ĺ�ϵ ��ȷ�����ֵ���λ
//�����ڵ���k����ĸ���: ��ȡ�� 
bool judge(int x) {
	ll ans = 0;
	int l = 0, r = -1;
	int num = 0;
	while(r < n) {
		cout<<"l: "<<l<<", r: "<<r<<endl;
		if(num < k) {
			if(a[r+1] >= x)	num++;
			r++;
		}
		else {
			if(num == k)
				ans += (n-r);
			if(a[l] >= x)
				num--;
			l++;
			cout<<"ans: "<<ans<<endl;
			if(ans >= m)
				return true;
			//ans>=m��˵�������k����ڵ���x������������ڵ���m��
			//��˵�����ǵ�mid��ʵ�ʴ�ҪС
		}
	}
	return false;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%lld", &n, &k, &m);
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		memcpy(b, a, sizeof(a));
		sort(b, b+n);
		int l = 0, r = n-1;
		int ans;
		while(l <= r) {
			int mid = (l+r)>>1;
			cout<<"mid: "<<mid<<", b[mid]: "<<b[mid]<<endl;
			if(judge(b[mid]))
				ans = b[mid], l = mid + 1;
			else
				r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
