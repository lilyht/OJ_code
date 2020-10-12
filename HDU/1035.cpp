#include <iostream>
#include <cstring>
using namespace std;
int n, m, start;
char mp[12][12];
int vis[12][12];
bool flag = false;
int beginl, loop;

void dfs(int x, int y, int step){
//	cout<<"dfs"<<x<<","<<y<<" "<<step<<endl;
	if(x>n || x<1 || y>m || y<1){
		cout<<step-1<<" step(s) to exit"<<endl;
		flag = true;
		return;
	}
	if(!flag){
		if(!vis[x][y]){
			vis[x][y] = step;
			if(mp[x][y] == 'N')	dfs(x-1, y, step+1);
			else if(mp[x][y] == 'S')	dfs(x+1, y, step+1);
			else if(mp[x][y] == 'W')	dfs(x, y-1, step+1);
			else	dfs(x, y+1, step+1);
		}
		else{
			beginl = vis[x][y] - 1;
			loop = step - vis[x][y];
		}
	}	
}

int main(){
	while(cin>>n>>m>>start){
		flag = false;
		loop = beginl = 0;
		memset(mp, 0, sizeof(mp));
		memset(vis, 0, sizeof(vis));
		if(n == 0 && m == 0 && start == 0)	break;
//		cin>>start;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				cin>>mp[i][j];
			}
		}
		dfs(1, start, 1);
		if(!flag)	cout<<beginl<<" step(s) before a loop of "<<loop<<" step(s)"<<endl;
	}
	
	return 0;
}
