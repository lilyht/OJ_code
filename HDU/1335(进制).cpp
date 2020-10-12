#include <iostream>
#include <string.h>
using namespace std;
//2020-09-08 22:20:54	Accepted	1335	15MS	1420K	1256 B	G++
char res[8];

int weishu(int temp) {
	int k = 0;
	while(temp) {
		temp = temp / 10;
		k++;
	}
	return k;
}

int main() {
	string s;
	int a, b;
	while(cin>>s>>a>>b) {
		int len = s.length();
		//先转换为十进制 
		int tmp = 0;
		int x;
		int c = 1;
		for(int i=len-1; i>=0; i--) {
			if(s[i] >= '0' && s[i] <= '9') {
				x = s[i] - '0';
			}
			else if(s[i] >= 'a' && s[i] <= 'z') {
				x = s[i] - 'a' + 10;
			}
			else if(s[i] >= 'A' && s[i] <= 'Z') {
				x = s[i] - 'A' + 10;
			}
			if(s[i] == ' ')	break;
			tmp += (x * c);
			c = c * a;
		}
		//tmp: 十进制 
		if(b == 10) {
			if(tmp <= 9999999) {
				int k = weishu(tmp);
				for(int i=0; i<7-k; i++)
					cout<<" ";
				cout<<tmp<<endl;
			}
			else
				cout<<"  ERROR"<<endl;
			continue;
		} 
		else {
			for(int i=0; i<7; i++)	res[i] = ' ';
			bool flag = 0;
			int idx = 7;
			while(tmp > 0) {
				int l = tmp % b;
				idx--;
				if(idx < 0) {
					cout<<"  ERROR"<<endl;
					flag = 1;
					break;
				}
				else {
					if(l >= 10)
						res[idx] = 'A' + (l - 10);
					else
						res[idx] = '0' + l;
				}
				tmp = tmp / b;
			}
			if(!flag) {
				for(int i=0; i<7; i++)
					cout<<res[i];
				cout<<endl;
			}
		}
	}
	return 0;
} 
