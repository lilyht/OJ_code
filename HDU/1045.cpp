#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int map[5][5];
int vis[5][5];
char ch;
int n;
int num, maxnum;

bool check(int x, int y){
	if(x > 0)
		for(int i=x-1; i>=0; i--){
			if(map[i][y] == 0)	break;  //ǽ 
			else if(map[i][y] == 2)	return false;
		}
	if(y > 0)
		for(int j=y-1; j>=0; j--){
			if(map[x][j] == 0)	break;
			else if(map[x][j] == 2)	return false;
		}
	return true;
}

void dfs(int k, int num){
	if(k == n*n){
		maxnum = max(maxnum, num);
		return;
	}
	else{
		int x = k/n;
		int y = k%n;
		if(map[x][y] == 1 && check(x, y)){
			map[x][y] = 2;
			dfs(k+1, num+1);
			map[x][y] = 1;
		}
		dfs(k+1, num);
	}
}

int main(){
	while(1){
		cin>>n;
		if(n == 0)	break;
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		num = maxnum = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>ch;
				if(ch == '.')	map[i][j] = 1;
				if(ch == 'X')	map[i][j] = 0;
			}
		}
		dfs(0, 0);
		cout<<maxnum<<endl;
	}
	
	return 0;
}
