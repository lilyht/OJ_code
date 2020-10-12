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
			buf[id++] = ch;  //��ȡÿ���ַ������ַ��ʹ��浽buf
		else {  //����ͷ����Ѿ�����Ļ�����
			buf[id] = '\0';
			id = 0;
			if(strcmp(buf, "END") == 0)	break;
			if(mp.find(buf) != mp.end()) {  //��map�в��� 
				cout<<mp[buf];  //�ҵ���Ӧ�ľ����
			} else
				printf("%s", buf);  //�������ԭ�ַ���
			putchar(ch);  //����alpha���Ƿ��ţ�ԭ����� 
			
		}
	}
	return 0;
}
