#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
//https://www.luogu.com.cn/problem/P1229

int ans = 1;
char a[10004];  //前序 
char b[10004];  //后序 
int main() {
	scanf("%s", &a);
	scanf("%s", &b);
	int len = strlen(a); 
	for(int i=0; i<len-1; i++) {
		for(int j=1; j<len; j++) {
			if(a[i] == b[j] && a[i+1] == b[j-1])
				ans *= 2;  //找到一个只有一个子节点的点，答案乘2 
		}
	}
	printf("%d\n", ans);
	return 0;
}
