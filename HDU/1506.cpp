#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll h[N], s[N], le[N], ri[N];

//�ο����ӣ�https://zhuanlan.zhihu.com/p/61423849 
int main() {
	int n, top;
	while(scanf("%d", &n), n) {
		for(int i = 1; i <= n; ++i)
			scanf("%I64d", &h[i]);

		top = 0, s[0] = 0;   //le[i]����i��ߵ�һ��С��h[i]���±�
		for(int i = 1; i <= n; ++i) {
			while(top && h[s[top]] >= h[i]) --top;  //ջ������ʵ�֣�ջ�ﱣ����ǵ���λ�� 
			le[i] = s[top];
//			cout<<"le["<<i<<"]: "<<le[i]<<endl;
			s[++top] = i;  //��ջ 
//			for(int j=0; j<=top; j++) cout<<s[j]<<" ";
//			cout<<endl;
//			cout<<"s["<<top<<"]: "<<s[top]<<endl;
		}
//		cout<<"================="<<endl;
		top = 0, s[0] = n + 1;  //ri[i]����i�ұ����һ�����ڵ���h[i]���±�
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
