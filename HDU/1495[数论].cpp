#include <iostream>
using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}

int main() {
	int s, n, m;
	while(~scanf("%d%d%d", &s, &n, &m) &&s&&n&&m) {
		if(s&1)
			printf("NO\n");
		else {
			int z = s / gcd(n, m);
			if(z&1)
				printf("NO\n");  //����жϱ����У�����wa 
			else
				printf("%d\n", z-1);
		}
	}
	
	return 0;
} 
