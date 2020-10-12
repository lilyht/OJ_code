#include <iostream>
#include <string.h> 
#include <algorithm>
using namespace std;
//2020-08-27 23:11:01	Accepted	1518	452MS	1392K	1044 B	G++
const int MAXN = 24;
int n, len;
bool flag = false;
int a[MAXN];
int vis[MAXN];

bool cmp(int x, int y) {
	return x > y;
}

void dfs(int num, int curlen, int start) {  //成功边数,目前长度,开始位置
	if(num == 3){  //三个都拼好了，最后一条边也可以 
		flag = true;  //不能使用return 1之类的了，因为这个是有回溯的 
		return;
	}
	if(curlen == len) {
		dfs(num+1, 0, 0);
		if(flag)  //已是可实现状态 
			return;
	}
	for(int i=start; i<n; i++) {
		if(!vis[i] && curlen+a[i]<=len) {
			vis[i] = 1;
			dfs(num, curlen+a[i], i+1);
			vis[i] = 0;
			if(flag)
				return;
		}
	}
	return;
}

int main() {
	int t, sum, maxa;
	cin>>t;
	while(t--) {
		cin>>n;
		sum = 0;
		maxa = 0;
		for(int i=0; i<n; i++) {
			cin>>a[i];
			sum += a[i];
			if(a[i] > maxa)	maxa = a[i];
		}
		len = sum / 4;  //边长 
		if(sum % 4 != 0 || maxa > sum/4) {
			cout<<"no"<<endl;
			continue;
		}
		memset(vis, 0, sizeof(vis));
		sort(a, a+n, cmp);
		flag = false;
		dfs(0, 0, 0);
		if(flag) {
			cout<<"yes"<<endl;
		}
		else
			cout<<"no"<<endl;
	}
	
	return 0;
}
