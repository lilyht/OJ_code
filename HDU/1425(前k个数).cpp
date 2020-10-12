#include <iostream>
#include <string.h>
using namespace std;
//2020-08-28 16:35:47	Accepted	1425	468MS	2352K	481B	G++
//因为空格和换行符WA一次 
int n, m;
bool b[1000005];

int main() {
	while(~scanf("%d", &n) && n) {
		int x;
		scanf("%d", &m);
		memset(b, 0, sizeof(b));
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			b[500000 + x] = 1;
		}
		int i;
		int cnt = 0;
		for(i=1000000; i>=0; i--) {
			if(b[i]) {
				cnt++;
				printf("%d", i-500000);
				//巧妙解决换行和空格问题 
				if(cnt == m) {
					printf("\n");
					break;
				}
				else
					printf(" ");
			}
		}
		
	}
	return 0;
} 
