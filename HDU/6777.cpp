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
//		for(int i=1; i<=110; i++) {  //时间
//			for(int j=1; j<=10; j++) {  //地点
//				for(int k=0; k<v[i][j].size(); k++) {
//					if(vis[v[i][j][k]] == 1) {
//						//全标记为1
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
//上面是自己写的代码，不知道哪里错了
//下面是网上的，一模一样的思路 
#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		int a[n+10] = {0,1}; //记录某一号人是否得病
		vector<int>se[120][15];  //一个三维数组，来表示在某一时刻的某一位置有谁
		int maxx=0;
		for(int i=1; i<=n; i++) { //i代表第几号人
			int m;
			scanf("%d",&m);
			/*预处理，将对应的人放在某一时刻的某一位置*/
			for(int j=1; j<=m; j++) {	//j来表示出门次数
				int p,q;
				scanf("%d%d",&p,&q);
				maxx=max(maxx,p);	//貌似没啥用
				se[p][q].push_back(i);	//将人放到对应的位置
			}
		}
		for(int i=1; i<=110; i++) {
			for(int k=1; k<=10; k++) {
				for(int j=0; j<se[i][k].size(); j++) {
					if(a[se[i][k][j]]==1) {//看看在i时刻j位置的人是否有得病的，如果有则将此时刻在这个位置的所有人都标记一下
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
				/*最后输出，貌似程序不卡这个格式的空格*/
				if(i==1)
					printf("%d",i);
				else
					printf(" %d",i);
			}
		}
		printf("\n");
	}
}

