#include <stdio.h>
int main() {
	double s[200];
	double num;
	while (scanf("%lf", &num) != EOF) {
		int n = 0;
		s[n++] = num;
		char c = getchar();
		if (num == 0 && c == '\n') {
			break;
		}
		char x;
		while(true) {
			scanf("%c %lf", &x, &num);
			switch(x) {
				case'+':
					s[n++] = num;
					break;
				case'-':
					s[n++] = -num;
					break;
				case'*':
					s[n-1] *= num;
					break;
				case'/':
					s[n-1] /= num;
					break;
			}
			if (getchar() == '\n') {
				break;
			}
		}
		double sum = 0;
		for (int i=0; i<n; i++) {
			sum += s[i];
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}
