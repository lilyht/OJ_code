#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
// Monkey and Banana 
// 参考 https://blog.csdn.net/guihaiyuan123/article/details/80088602 
int b[3];
int dp[200];

struct rec{
	int x, y, z;
}a[200];

bool cmp(rec p, rec q) {
	if(p.x != q.x)	return p.x > q.x;
	else if(p.y != q.y)	return p.y > q.y;
	else	return p.z > q.z;
}

int main() {
	int n;
	int kse = 0;
	while(cin>>n && n) {
		int index = 0;
		int ans = 0;
		memset(b, 0, sizeof(b));
		
		for(int i=0; i<n; i++) {
			cin>>b[0]>>b[1]>>b[2];
			sort(b, b+3);
			a[index].z = b[0];
			a[index].x = b[2];
			a[index].y = b[1];
			index++;
			a[index].z = b[1];
			a[index].x = b[2];
			a[index].y = b[0];
			index++;
			a[index].z = b[2];
			a[index].x = b[1];
			a[index].y = b[0];
			index++;
		}
		sort(a, a+index, cmp);
		//dp——求最长（最大）递增子序列 
		dp[0] = a[0].z;
		for(int i=1; i<index; i++)
			dp[i] = a[i].z; 
/*
 *                      i  -->外循环 
 *                      | 
 *  数组： x1  x2  x3  x4  x5 ... x8 
 *             |
 *             j  -- >
 */
		for(int i=1; i<index; i++) {
			for(int j=0; j<i; j++) {
				if(a[i].x < a[j].x && a[i].y < a[j].y) {
					//符合条件
					dp[i] = max(dp[i], dp[j]+a[i].z);
				}
			}
			ans = max(ans, dp[i]);  //notice！ 
		}
		cout<<"Case "<<++kse<<": maximum height = "<<ans<<endl;
	}
	
	return 0;
}
/*
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
-----------
Case 1: maximum height = 40
Case 2: maximum height = 21
Case 3: maximum height = 28
Case 4: maximum height = 342
*/ 
