#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 400;
//2020-09-13 16:58:44	Accepted	1083	1123MS	2032K	792 B	G++
//二分图 
int t, p, n;
int mp[MAXN][MAXN];  //保存输入的相互关系
bool mark[MAXN];  //是否查找过
int rec[MAXN];  //保存匹配关系

bool find(int x) {  //对这个（x号）课程找匹配的学生 
	int i;
	for(i=1; i<=n; i++) {  //遍历学生 
		if(!mark[i] && mp[x][i] == 1) {  //这个mark数组在每次查找x之前都要清空，但是注意不能在find函数中清空，否则会死循环 
			mark[i] = 1;  //标记为已访问 
			if(rec[i] == -1 || find(rec[i])) {  //这个学生还没有匹配给其他课程，或者这个学生匹配的课程还可以匹配到其他学生 
				rec[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin>>t;
	while(t--) {
		memset(mp, 0, sizeof(mp));
		memset(rec, -1, sizeof(rec));
		cin>>p>>n;
		int j, k;
		for(int i=1; i<=p; i++) {
			cin>>k;
			while(k--) {
				cin>>j;
				mp[i][j] = 1;
			}
		}
		int cnt = 0;
		for(int i=1; i<=p; i++) {
			memset(mark, 0, sizeof(mark));
			if(find(i)) {
				cnt++;
			}
		}
		if(cnt == p)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
} 
