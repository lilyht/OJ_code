//#include <iostream>
//#include <vector>
//#include <string.h>
//using namespace std;
//
//bool vis[20010];
//
//int main() {
//	int t, n, tm, p;
//	scanf("%d", &t);
//	while(t--) {
//		memset(vis, 0, sizeof(vis));
//		vector<int> v[120][15];
//		scanf("%d", &n);
//		int len;
//		for(int i=1; i<=n; i++) {
//			scanf("%d", &len);
//			for(int j=0; j<len; j++) {
//				scanf("%d%d", &tm, &p);
//				v[tm][p].push_back(i);
//			}
//		}
//		vis[1] = 1;
//		for(int i=1; i<=110; i++) {  //ʱ��
//			for(int j=1; j<=10; j++) {  //�ص�
//				for(int k=0; k<v[i][j].size(); k++) {
//					if(vis[v[i][j][k]] == 1) {
//						//ȫ���Ϊ1
//						for(int l=0; l<v[i][j].size(); l++) {
//							vis[v[i][j][l]] = 1;
//						}
//					}
//					break;
//				}
//			}
//		}
//		printf("%d", 1);
//		for(int i=2; i<=n; i++) {
//			if(vis[i]) {
//				printf(" %d", i);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//�������Լ�д�Ĵ��룬��֪���������
//���������ϵģ�һģһ����˼· 
#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		int a[n+10] = {0,1}; //��¼ĳһ�����Ƿ�ò�
		vector<int>se[120][15];  //һ����ά���飬����ʾ��ĳһʱ�̵�ĳһλ����˭
		int maxx=0;
		for(int i=1; i<=n; i++) { //i����ڼ�����
			int m;
			scanf("%d",&m);
			/*Ԥ��������Ӧ���˷���ĳһʱ�̵�ĳһλ��*/
			for(int j=1; j<=m; j++) {	//j����ʾ���Ŵ���
				int p,q;
				scanf("%d%d",&p,&q);
				maxx=max(maxx,p);	//ò��ûɶ��
				se[p][q].push_back(i);	//���˷ŵ���Ӧ��λ��
			}
		}
		for(int i=1; i<=110; i++) {
			for(int k=1; k<=10; k++) {
				for(int j=0; j<se[i][k].size(); j++) {
					if(a[se[i][k][j]]==1) {//������iʱ��jλ�õ����Ƿ��еò��ģ�������򽫴�ʱ�������λ�õ������˶����һ��
						for(int p=0; p<se[i][k].size(); p++) {
							a[se[i][k][p]]=1;
						}
						break;
					}
				}
			}
		}
		for(int i=1; i<=n; i++) {
			if(a[i]) {
				/*��������ò�Ƴ��򲻿������ʽ�Ŀո�*/
				if(i==1)
					printf("%d",i);
				else
					printf(" %d",i);
			}
		}
		printf("\n");
	}
}

