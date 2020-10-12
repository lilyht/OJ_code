#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//2020-09-21 15:48:08	Accepted	1321	15MS	1392K	288 B	G++
char str[100];
int main() {
	int t;
	scanf("%d", &t);
	getchar();
	while(t--) {
		gets(str);
		string s;
		s = str;
		reverse(s.begin(), s.end());
		printf("%s", s.c_str());
		printf("\n");
	}
	return 0;
}
