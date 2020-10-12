#include <cstdio>
#include <cstring> 
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull base = 131;
ull a[10010];
char s[10010];
//C++
ull hashs(char s[]) {
	int len = strlen(s);
	ull ans = 0;
	for(int i=0; i<len; i++)
		ans = ans*base + (ull)s[i];  //s[0]='a'-->数字等于97
//	printf("ans: %d\n", ans);
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%s", s);
		a[i] = hashs(s);
//		printf("==\n");
	}
	sort(a, a+n);  //按哈希值排序，值相等的就挨在一起了
	int cnt = 1;
	for(int i=1; i<n; i++) {
		if(a[i-1] != a[i])
			cnt++;
	} 
	printf("%d\n", cnt);
	
	return 0;
}
