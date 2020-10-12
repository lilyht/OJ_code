#include <iostream>
#include <algorithm>
using namespace std;

// kruskal�㷨
//����ϡ��ͼ���ʹ������㷨 

int f[30];
int n, k, cost;
char a, b;

struct node{
	char e1, e2;
	int dis;
}p[10000];

int find(int x) {
//	cout<<x<<endl;
	if(f[x] == x) 	return x;
	return find(f[x]);
} 

bool cmp(node x, node y) {
	return x.dis < y.dis;
}

int main() {
	while(cin>>n && n) {
		int num = 0; 
		//��ʼ�����鼯
		for(int i=0; i<=27; i++)
			f[i] = i;
		
		for(int l=1; l<n; l++) {
			cin>>a>>k;
			for(int i=0; i<k; i++) {
				cin>>b;
				p[num].e2 = b - 'A' + 1;
				cin>>p[num].dis;
				p[num].e1 = a - 'A' + 1;
				num++;  //��·���� 
			}
		}
		
		int ans = 0;
		//��С��������
		sort(p, p+num, cmp); 
		//�������еĵ�· 
		for(int i=0; i<num; i++) {
			int fx = find(p[i].e1);
			int fy = find(p[i].e2);
			//�ж��Ƿ���ͨ 
			if(fx != fy) {
				//����ͨ 
				ans += p[i].dis;
				f[fx] = fy; 
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
