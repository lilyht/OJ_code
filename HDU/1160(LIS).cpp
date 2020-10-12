#include <iostream>
#include <string.h>
#include <algorithm>
#include <stack> 
using namespace std;
//2020-08-19 16:26:33	Accepted	1160	15MS	1424K	1087 B	G++
//好难想啊，还需要再看 
const int INF = 999999999;
struct mouse{
	int size;
	int speed;
	int id;
}a[1005];
int dp[1005]; 
int pre[1005];  //记录路径 

bool cmp(mouse x, mouse y) {
	if(x.size == y.size)
		return x.speed > y.speed;
	return x.size < y.size;
}

int main() {
	int index = 1, s1, s2;
	while(cin>>s1>>s2) {
		a[index].size = s1;
		a[index].speed = s2;
		a[index].id = index++;
	}
	sort(a+1, a+index+1, cmp);
	
	//dp--O(nlogn) 
	dp[0] = 0;
	int ans = 0;
	for(int i=1; i<=index; i++) {
		pre[i] = -1;
		dp[i] = 1;
		for(int j=1; j<i; j++) {
			if(a[i].size > a[j].size && a[i].speed < a[j].speed && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				pre[i] = j; 
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout<<ans<<endl;
	int flag = -1;
	for(int i=1; i<=index; i++) {
		if(dp[i] == ans)
			flag = i;
	}
	stack<int> st;
	st.push(a[flag].id);
	flag = pre[flag];
	while(flag != -1) {
		st.push(a[flag].id);
		flag = pre[flag];
	}
	while(!st.empty()) {
		cout<<st.top() + 1<<endl;
		st.pop();
	}
	
	return 0;
}
