#include <iostream>
using namespace std;

int a[26];
int main() {
	int n;
	while(~scanf("%d", &n)) {
		int sum = 0;
		int ans = 1;
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		for(int i=sum; i>=1; i--) {
			ans = ans * i;
		}
		for(int i=0; i<n; i++) {
			ans = ans / a[i];
		}
		printf("%d\n", ans);
	}
	return 0;
} 
