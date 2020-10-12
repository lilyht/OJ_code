#include <iostream>
#include <cstring>
using namespace std;
int order[22];
int vis[22];
int n;

bool prime(int x){
	for(int i=2; i<=x/2; i++){
		if(x%i == 0)	return false;
	}
	return true;
}

void dfs(int step){
	if(step == n+1){
		if(prime(order[1] + order[n])){
			for(int i=1; i<=n-1; i++)	cout<<order[i]<<" ";
			cout<<order[n]<<endl;
			return;
		}
	}
	for(int i=2; i<=n; i++){
		if(!vis[i] && prime(i+order[step-1])){
			vis[i] = 1;
			order[step] = i;
			dfs(step+1);
			vis[i] = 0;
		}
	}
}

int main(){
	int cnt = 0;
	while(cin>>n){
		cnt++;
		memset(order, 0, sizeof(order));
		memset(vis, 0, sizeof(vis));
		cout<<"Case "<<cnt<<":"<<endl;
		order[1] = 1;
		vis[1] = 1;
		dfs(2);
		cout<<endl;
	}
	
	return 0;
}
