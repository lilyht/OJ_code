#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<string.h>
using namespace std;

int t, k, sum, i, j;
long long ans;
int vis[30];
const int maxn = 1e6+50;
char s[maxn];  //�� 

int change(char c) {
	return (int)c - 'a';
}

int main() {
	scanf("%d",&t);
	while(t--) {
		i = 0;
		j = 0;
		ans = 0;
		sum = 0;
		memset(vis,0,sizeof(vis));
		scanf("%s%d", s, &k);
		int n = strlen(s);
		while(1) {
			while(j<n && sum<k) {
				if(!vis[change(s[j])])  //����ո���������һ���µ��ַ�
					sum++;
				vis[change(s[j])]++;
				j++;
			}//while
			if(sum<k || j>n)	break;
			ans += n-j+1;  //��������ַ�����ʼ��ÿ������һ����ĸ������������ 
			
			vis[change(s[i])]--;
			if(!vis[change(s[i])])
				sum--;  // �����С��˵������ַ�ȥ��֮���ִ��ַ��ĸ���û���ˣ��ַ�������һ
			i++;  //����������һλ 
		}//while(1)
		printf("%lld\n", ans);
	}
	return 0; 
}


