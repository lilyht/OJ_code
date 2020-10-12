////哈希失败，TLE，不知道为嘛
//#include <iostream>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//typedef unsigned long long ull;
//const int MAXN = 100005;
//ull base = 131;
//ull hashval = 0;
//ull a[MAXN];
//int num[MAXN];
//char s[36];
//
//ull hashs(char s[]) {
//	int len = strlen(s);
//	ull ans = 0;
//	for(int i=0; i<len; i++) {
//		ans = ans*base + (ull)s[i];
//	}
//	return ans;
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	int idx = 0;
//	int flag = 0;
//	memset(num, 0, sizeof(num));
//	for(int i=0; i<n; i++) {
//		scanf("%s", s);
//		hashval = hashs(s);
//		int j, p;
//		idx++;
//		flag = 0;
//		for(j=0; j<idx; j++) {
//			if(hashval == a[j]) {
//				num[j]++;
//				p = j;
//				flag = 1;
//			}
//		}
//		if(flag == 0) {
//			//new
//			printf("OK\n");
//			a[idx] = hashval;
//			num[idx] = 0;
//
//		}
//		else
//			printf("%s%d\n", s, num[p]);
//	}
//
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
struct node {
	string n;
	int num;
};
node a[100005];
int main() {
	int b=0;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		string c;
		cin>>c;
		bool flag=0;
		for(int j=0; j<=b; j++)
			if(a[j].n == c) {
				a[j].num++;
				cout<<a[j].n<<a[j].num<<endl;
				flag=1;
				break;
			}
		if(!flag) {
			cout<<"OK"<<endl;
			a[b++].n=c;
		}
	}
	return 0;
}

