#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll h[N], s[N], le[N], ri[N];

//参考链接：https://zhuanlan.zhihu.com/p/61423849 
int main() {
	int n, top;
	while(scanf("%d", &n), n) {
		for(int i = 1; i <= n; ++i)
			scanf("%I64d", &h[i]);

		top = 0, s[0] = 0;   //le[i]保存i左边第一个小于h[i]的下标
		for(int i = 1; i <= n; ++i) {
			while(top && h[s[top]] >= h[i]) --top;  //栈的数组实现，栈里保存的是单调位置 
			le[i] = s[top];
//			cout<<"le["<<i<<"]: "<<le[i]<<endl;
			s[++top] = i;  //进栈 
//			for(int j=0; j<=top; j++) cout<<s[j]<<" ";
//			cout<<endl;
//			cout<<"s["<<top<<"]: "<<s[top]<<endl;
		}
//		cout<<"================="<<endl;
		top = 0, s[0] = n + 1;  //ri[i]保存i右边最后一个大于等于h[i]的下标
		for(int i = n; i > 0; --i) {
			while(top && h[s[top]] >= h[i]) --top;
			ri[i] = s[top] - 1;
//			cout<<"ri["<<i<<"]: "<<ri[i]<<endl;
			s[++top] = i;
//			cout<<"s["<<top<<"]: "<<s[top]<<endl;
		}

		ll ans = h[1];
		for(int i = 1; i <= n; ++i)
			if(h[i] * (ri[i] - le[i]) > ans)
				ans =  h[i] * (ri[i] - le[i]);
		printf("%I64d\n", ans);
	}
	return 0;
}
