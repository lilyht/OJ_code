#include <iostream>
#include <string.h>
using namespace std;
//2020-09-05 23:31:34	Accepted	2063	15MS	2404K	729B	G++
int n, m;  //m: 女生的人数，n: 男生的人数
int cp[505][505];
int girl[505];
bool used[505];
int find(int x) {
	for(int i=1; i<=m; i++) {
		if(cp[x][i] == 1 && used[i] == 0) {
			used[i] = 1;
			if(girl[i] == 0 || find(girl[i])) {  //女生未被选择或被该女生选择的男生有其他选择
				girl[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int k, a, b;
	while(cin>>k && k) {
		cin>>m>>n;
		memset(girl, 0, sizeof(girl));
		memset(cp, 0, sizeof(cp));
		for(int i=1; i<=k; i++) {
			cin>>a>>b;
			cp[b][a] = 1;
		}
		int sum = 0;
		for(int i=1; i<=n; i++) {
			memset(used, 0, sizeof(used));
			if(find(i) == 1)
				sum++;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
