#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define LL long long
#define Maxn 100005
using namespace std;
//2020-09-14 13:35:27	Accepted	6776	405MS	2940K	463 B	G++
LL a[Maxn];
LL s[Maxn];

int main() {
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++)	scanf("%d",&a[i]);
		sort(a, a+n);
		for(int i=0; i<n-1; i++)
			s[i] = a[i+1] - a[i];
		LL Ans = 0;
		for(int i=0; i<n-1; i++)
			Ans += s[i] * (n - i - 1) * (i + 1);
		printf("%lld\n", Ans);
	}
}

