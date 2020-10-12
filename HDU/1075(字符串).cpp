#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <ctype.h>
#include <algorithm>
using namespace std;
//2020-08-21 11:25:56	Accepted	1075	967MS	73148K	786 B	G++ 
int main() {
	char buf[12], s1[12], s2[12], ch;
	map<string, string> mp;
	int id = 0;
	gets(buf);
	while(scanf("%s%s", s1, s2), strcmp(s1, "END")) {
		mp[s2] = s1;
	}
	getchar();
	while(scanf("%c", &ch)) {
		if(isalpha(ch))
			buf[id++] = ch;  //读取每个字符，是字符就储存到buf
		else {  //否则就翻译已经输入的火星文
			buf[id] = '\0';
			id = 0;
			if(strcmp(buf, "END") == 0)	break;
			if(mp.find(buf) != mp.end()) {  //从map中查找 
				cout<<mp[buf];  //找到对应的就输出
			} else
				printf("%s", buf);  //否则输出原字符串
			putchar(ch);  //不是alpha，是符号，原样输出 
			
		}
	}
	return 0;
}
