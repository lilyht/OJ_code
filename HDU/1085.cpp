#include <iostream>
using namespace std;
//1085

int main() {
	int x, y, z;
	while(~scanf("%d%d%d", &x, &y, &z) && x+y+z) {
		if(x == 0)	printf("1\n");
		else {
			if(x+2*y < 4) 	printf("%d\n", x+2*y+1);
			else	printf("%d\n", x+2*y+5*z+1);
		}
	}
	return 0;
} 

