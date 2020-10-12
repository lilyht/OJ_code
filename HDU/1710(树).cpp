#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
//题目是给出了前序遍历和中序遍历，求后序遍历 
//2020-07-21 22:02:15	Accepted	1710	109MS	1804K	748 B	C++
const int maxn = 1005;
int pre[maxn], mi[maxn];
int pid;  //记录前序遍历中根节点的位置
vector<int> v;

void pos(int l, int r) {
	int i = l;
	while(mi[i] != pre[pid])
		i++;  //找到中序中的根节点位置 
	if(i > l) {
		pid++;  //前序遍历中根节点的位置 
		pos(l, i-1);
	}
	if(i < r) {
		pid++;  //前序遍历中根节点的位置
		pos(i+1, r);
	}
//	printf("%d---", mi[i]);
	v.push_back(mi[i]);
}

int main() {
	int n;
	while(cin >> n) {
		pid = 0;
		for(int i=0; i<n; i++)
			cin>>pre[i];
		for(int i=0; i<n; i++)
			cin>>mi[i];
		pos(0, n-1);
		for(int i=0; i<n; i++)
			printf("%d%c", v[i], i==n-1?'\n':' ');
		v.clear();
	}
	return 0;
}
