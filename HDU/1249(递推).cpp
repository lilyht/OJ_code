#include<stdio.h>
#include <iostream>
using namespace std;
//https://developer.aliyun.com/article/19174
//2020-09-19 23:15:03	Accepted	1249	0MS	1364K	234B	G++
int main() {	 
	int n, m;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &m);
		printf("%d\n", 3 * m * (m-1) + 2);
	}
	return 0;
}
