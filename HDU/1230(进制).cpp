#include "iostream"
#include "stdio.h"
#include "math.h"
#include "vector"
#include "queue"
#include "memory.h"
#include "algorithm"
#include "string"
#include "string.h"
using namespace std;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
//2020-08-22 22:05:38	Accepted	1230	31MS	1368K	2903B	G++
int prim[27] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

int Analyse(char *s,int* res) {
	int t=0;
	int x=0;
	int i=0;
	while(i<strlen(s)) {
		if(s[i]==',') {
			i++;
			res[t++]=x;
			x=0;
			continue;
		}
		x*=10;
		x+=s[i]-'0';
		i++;
	}
	res[t++]=x;
	return t-1;//array length
}

void Trans(char *s1,char *s2) {
	int s[30];
	memset(s,0,sizeof(s));
	int i,j,x;
	int a[30],b[30];
	int lena=Analyse(s1,a);
	int lenb=Analyse(s2,b);
	int len=max(lena,lenb);
	for(i=0; i<=len; i++) {
		x=s[i];
		if(i<=lena)
			x+=a[lena-i];
		if(i<=lenb)
			x+=b[lenb-i];
		s[i]=x%prim[i];
		s[i+1]+=x/prim[i];
	}
	while(s[i]==0)
		i--;
	while(i>0)
		printf("%d,",s[i--]);
	printf("%d\n",s[i]);
}

int main() {
	//CalPrim();
	int len,lena,lenb;
	char a[100],b[100];
	while(scanf("%s%s",a,b)) {
		if(strcmp(a,"0")==0&&strcmp(b,"0")==0)
			break;
		Trans(a,b);
	}
}
//#include <iostream>
//#include <string.h>
//#include <string>
//#include <algorithm>
//using namespace std;
//
////int prime[1000] = {0};
//bool isPrim[1000];
//int prime[26] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
//int ans[30];
//
//void init() {
//	int idx = 1;
//	memset(isPrim, true, sizeof(isPrim));
//	for(int i=2; i<=1000; i++) {
//		if(isPrim[i]) {
//			prime[idx++] = i;
//		}
//		for(int j=i+i; j<=1000; j+=i) {
//			isPrim[j] = 0;  //不是质数
//		}
//	}
//}
//
//int main() {
//	//生成素数表
////	init();
//	string a, b, maxstr;
//	while(cin>>a>>b && a != "0" && b != "0") {
//		reverse(a.begin(), a.end());
//		a = a;
//		reverse(b.begin(), b.end());
//		b = b;
//		memset(ans, 0, sizeof(ans));
//		int lena = a.length();
//		int lenb = b.length();
//		int maxlen;
//		if(lena > lenb)	maxlen = lena,	maxstr = a;
//		else{
//			maxlen = lenb;
//			maxstr = b;
//		}
////		cout<<a<<"*"<<b<<endl;
//		int cf = 0;  //进位位
//		int idx = 0;
//		int i = 0;
//		for(i=0; i<min(lena, lenb); i+=2) {
//			int x = a[i]-'0' + b[i]-'0' + cf;
//			if(x >= prime[i/2 + 1]) {
////				cout<<"=="<<endl;
//				ans[idx] = x % prime[i/2 + 1];
////				cout<<ans[idx]<<endl;
//				cf = x / prime[i/2 + 1];
//				idx++;
//			}
//			else {
//				ans[idx] = x;
//				idx++;
//			}
//		}
//		for(int j=i; j<maxlen; j+=2) {
//			cout<<"j: "<<j<<endl;
//			int x = maxstr[j]-'0' + cf;
//			cout<<"x: "<<x<<endl;
//			cout<<"p[j/2+1]: "<<prime[j/2+1]<<endl;
//			ans[idx] = x % prime[j/2 + 1];
//			cf = x / prime[j/2 + 1];
//			idx++;
//		}
//		if(cf != 0)
//			ans[idx++] = cf;
//		for(int i=idx-1; i>0; i--)
//			cout<<ans[i]<<",";
//		cout<<ans[0]<<endl;
//	}
//
//	return 0;
//}
/*
1,0 2,1
4,2,0 1,2,0
1 10,6,4,2,1
0 0
*/
