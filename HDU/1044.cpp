#include <iostream>
#include <cstring>
using namespace std;
int map[52][52];
bool vis[52][52];
int a[10];

int w, h, l, m;

int main(){
	int t;
	char ch;
	cin>>t;
	while(t--){
		cin>>w>>h>>l>>m;
		//init
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<m; i++)	cin>>a[i];
		for(int i=0; i<w; i++){
			for(int j=0; j<h; j++){
				cin>>ch;
				if(ch == '@'){
					sx = i;
					sy = j;
					map[i][j] = 0;
				}
				else if(ch == '<'){
					ex = i;
					ey = j;
					map[i][j] = 0;
				}
				else if(ch == '*')
					map[i][j] = -1;
				else if(ch >= 'A' && ch <= 'J')
					map[i][j] = ch-'A';
				else
					map[i][j] = 1;
			}
		}
		//dfs
		
	}
	
	return 0;
}
