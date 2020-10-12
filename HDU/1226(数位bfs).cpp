#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
//不会做，看了网上的代码  https://blog.csdn.net/mengxiang000000/article/details/50669300 
struct node {
	int a[502];
	int len;
} now;

int n,c,m;
int num[17];
int vis[5005];
int judge(node &b) {
	int tmp=0;
	for(int i=0; i<b.len; i++) {
		tmp=(tmp*c+b.a[i])%n;  //由于是n进制，tmp在前面的基础上乘以进制数c再加上下一位。如果能整除n，那必定是n的倍数，则成立
	}
	return tmp;
}

void print(node &p) {
	for(int i=0; i<p.len; i++) {
		if(p.a[i]>=0&&p.a[i]<=9)
			printf("%d",p.a[i]);
		else {
			printf("%c",p.a[i]-10+'A');
		}
	}
	printf("\n");
}

int bfs() {
	memset(vis,0,sizeof(vis));
	queue<node> s;
	for(int i=1; i<=15; i++) {  //由于第一位不能是0，所以从1开始(总共有15种)
		if(num[i]==1) {  //这个数是给出的样例 
			now.a[0]=i;
			now.len=1;
			int tmp=judge(now);
			if(tmp==0) {  //模为0，则肯定是n的倍数，输出
				print(now);
				return 1;
			} else {  //余数不能与之前出现过的余数相同，因为前面出现过的序列，肯定包含同样余数却在后面出现的序列
				vis[tmp]=1;  //标记该余数已被访问
				s.push(now);  
			}
		}
	}
	while(!s.empty()) {
		now=s.front();
		s.pop();
		for(int i=0; i<=15; i++) {
			if(num[i]==1) {
				now.a[now.len]=i;
				now.len++;
				int tmp=judge(now);
				if(tmp==0) {  //一直找到能整除n的方案
					print(now);
					return 1;
				} else {
					if(vis[tmp]==0&&now.len<499) {
						vis[tmp]=1;
						s.push(now);
					}
				}
				now.len--;  //控制每次循环都是一个一个拓展过去的
			}
		}
	}
	return 0;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		memset(num,0,sizeof(num));
		scanf("%d%d%d",&n,&c,&m);
		for(int i=0; i<m; i++) {
			char str[5];
			scanf("%s",str);
			if(str[0]>='0'&&str[0]<='9')
				num[str[0]-'0']=1;
			else
				num[str[0]-'A'+10]=1;
		}
		if(n==0) {
			if(num[0]==1) {
				printf("0\n");
			} else {
				printf("give me the bomb please\n");
			}
			continue;
		}
		if(bfs()==0) {
			printf("give me the bomb please\n");
		}
	}
}
