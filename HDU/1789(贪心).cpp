#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
//2020-09-17 08:39:24	Accepted	1789	93MS	1420K	785 B	G++
/*
 * ̰�Ĳ��ԣ�
 * �����ǣ�
 * ���������ͬ���Կ۷ֶ�ĴӴ�С���У�����۷���ͬ�������޴�С�������С�
 * ���Ų��ԣ�ÿ�Ź�������ڸ�����deadline�������ɣ��粻����ɣ�ֻ����ǰ����һ�컹ûʹ�ã�����ʹ�������Ź��ε�����Խ��Խ�ã�
 * �������ֹ���ڵ���һ�죬���һ·�������Ѿ�����ǹ��ˣ������j==0˵���Ѿ�û���㹻��һ��ʱ����������Ź��Σ���ô�ͽ����Ź��ο۵ķ����ӵ�ans��
 * ���յ�ans��Ϊ��С�۷�ֵ
 */ 
//�ο����ͣ�https://www.cnblogs.com/acgoto/p/8526303.html 
bool vis[MAXN];
struct node{
	int ddl;
	int cost;
}a[MAXN];

bool cmp(node x, node y) {
	if(x.cost != y.cost)
		return x.cost > y.cost;
	else
		return x.ddl < y.ddl;
}

int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>a[i].ddl;
		}
		for(int i=0; i<n; i++) {
			cin>>a[i].cost;
		}
		sort(a, a+n, cmp);
//		for(int i=0; i<n; i++)
//			cout<<a[i].ddl<<" "<<a[i].cost<<endl;
		memset(vis, 0, sizeof(vis));
		int ans = 0;
		int j;
		for(int i=0; i<n; i++) {
			for(j=a[i].ddl; j>0; j--) {
				if(!vis[j]) {
					vis[j] = 1;
					break;
				}
			}
			if(j == 0)
				ans += a[i].cost;
		}
		cout<<ans<<endl;
	} 
	return 0; 
} 
