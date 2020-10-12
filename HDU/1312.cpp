#include <iostream>
#include <string.h>
using namespace std;

int w, h, cnt;
int mp[24][24];
int dx[5] = {0, 0, 1, -1, 0};
int dy[5] = {1, -1, 0, 0, 0};

int dfs(int x, int y) {
	for(int i=0; i<=4; i++) {
		int x_ = x + dx[i];
		int y_ = y + dy[i];
		if(x_>=0 && x_<w && y_>=0 && y_<h) {
			if(mp[x_][y_] != 0) {
				mp[x_][y_] = 0;
				cnt++;
				dfs(x_, y_);
			}
		}
	}
}

int main() {
	while(cin>>h>>w && w+h) {
		int sx = 0;
		int sy = 0;  // ÆðÊ¼×ø±ê 
		char ch;
		cnt = 0;
		memset(mp, 0, sizeof(mp));
		for(int i=0; i<w; i++) {
			for(int j=0; j<h; j++) {
				cin>>ch;
				if(ch == '.')	mp[i][j] = 1;
				if(ch == '@') {
					mp[i][j] = 1;
					sx = i;
					sy = j;
				}
				if(ch == '#')	mp[i][j] = 0;
			}
		}
		dfs(sx, sy);
		cout<<cnt<<endl;
	}
	
	return 0;
}
