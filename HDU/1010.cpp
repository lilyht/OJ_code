#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int mp[8][8];
bool flag = false;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int m, n, t;
int sx, sy, ex, ey;
char ch;

void dfs(int x, int y, int step){
	if(flag)	return;
	if(x == ex && y == ey){
		if(step == t){
			flag = true;
			return;
		}
		else
			return;
	}
	for(int i=0; i<4; i++){
		int x_ = x + dx[i];
		int y_ = y + dy[i];
		if(x_ >= 1 && x_ <= m && y_ >= 1 && y_ <= n && !mp[x_][y_]){
			mp[x_][y_] = 1;
			step += 1;
			dfs(x_, y_, step);
			mp[x_][y_] = 0;
			step -= 1;
		}
	}
}

int main(){
	while(1){
		memset(mp, 0, sizeof(mp));
		cin>>m>>n>>t;
		if(m == 0 && n == 0 && t == 0)	break;
//		cout<<m<<" "<<n<<endl;
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				cin>>ch;
				if(ch == '.')	mp[i][j] = 0;
				else if(ch == 'X')	mp[i][j] = 1;
				else if(ch == 'S'){
					sx = i;
					sy = j;
					mp[i][j] = 1;
				}
				else{ // ch == 'D;
					ex = i;
					ey = j;
					mp[i][j] = 0;
				}
			}
		}
		if(abs(ex - sx) + abs(ey - sy) > t){
			cout<<"NO"<<endl;
			continue;
		}
		//deal
		flag = false;
		dfs(sx, sy, 0);
		if(flag == 1)	cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	
	return 0;
}
