#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
//���������������ϵĴ���  https://blog.csdn.net/mengxiang000000/article/details/50669300 
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
		tmp=(tmp*c+b.a[i])%n;  //������n���ƣ�tmp��ǰ��Ļ����ϳ��Խ�����c�ټ�����һλ�����������n���Ǳض���n�ı����������
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
	for(int i=1; i<=15; i++) {  //���ڵ�һλ������0�����Դ�1��ʼ(�ܹ���15��)
		if(num[i]==1) {  //������Ǹ��������� 
			now.a[0]=i;
			now.len=1;
			int tmp=judge(now);
			if(tmp==0) {  //ģΪ0����϶���n�ı��������
				print(now);
				return 1;
			} else {  //����������֮ǰ���ֹ���������ͬ����Ϊǰ����ֹ������У��϶�����ͬ������ȴ�ں�����ֵ�����
				vis[tmp]=1;  //��Ǹ������ѱ�����
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
				if(tmp==0) {  //һֱ�ҵ�������n�ķ���
					print(now);
					return 1;
				} else {
					if(vis[tmp]==0&&now.len<499) {
						vis[tmp]=1;
						s.push(now);
					}
				}
				now.len--;  //����ÿ��ѭ������һ��һ����չ��ȥ��
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
