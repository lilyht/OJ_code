# include<iostream>
# include<cstdio>
# include<string>
# include<cstring>
# include<stack>
using namespace std;
const int MAXN = 16;
const int INF = 0xffffff;
/*  参考教程：https://www.cnblogs.com/acm-bingzi/p/3278900.html 
 * https://blog.csdn.net/libin56842/article/details/24316493 
 * 详细说明：http://blog.sina.com.cn/s/blog_8e0ea6d50101r17u.html 
 */ 

struct Homework {
	string name;
	int deadline;    //截止时间
	int time;    //完成时间
} data[MAXN];

struct {
	int time;    //完成该集合作业所需时间
	int score;    //完成该集合作业被扣学分
	int last;    //记录上一个位置
	int pos;    //记录当前位置
} dp[1<<MAXN];

int main() {
	int T,n;
	int i;
	cin>>T;
	while(T--) {
		cin>>n;
		for(i=0; i<n; i++)
			cin>>data[i].name>>data[i].deadline>>data[i].time;
		int endstate = 1<<n;
		int recent = 0;
		int reduce = 0;
		int past = 0;
		for(int S=1; S<endstate; S++) {
			dp[S].score  = INF;
//			cout<<"===S: "<<S<<endl;
			for(i=n-1; i>=0; i--) {
				recent = 1<<i;  ////左移i位
				if(S & recent) {  //如果位置i上的作业是完成的
					past = S - recent;    //i上位置没完成的为前一个状态
//					cout<<"past: "<<past<<endl; 
					reduce = dp[past].time + data[i].time - data[i].deadline;    //完成该作业被扣学分，小于0则不扣  //从前一个状态到这个状态扣掉的总分
					if(reduce < 0)  //如果小于零就证明提前完成了所以也就是没扣分
						reduce = 0;
					if(reduce + dp[past].score < dp[S].score) {
						dp[S].time = dp[past].time + data[i].time;
						dp[S].score = reduce + dp[past].score;
						dp[S].pos = i;
						dp[S].last = past;
					}
				}
			}
		}
		 //构建一个栈用来输出完成作业的顺序用一个数组倒序存，顺序输出即可
		stack<int >path;    //保存路径
		recent = endstate - 1;    //1<<n - 1，表示n个1的2进制数，即全集
		while(recent) {
			path.push(dp[recent].pos);
			recent = dp[recent].last;
		}
		cout << dp[endstate-1].score<<endl;
		while(!path.empty()) {
			int top = path.top();
			cout<<data[top].name<<endl;
			path.pop();
		}
	}
	return 0;
}

//贪心算法不对
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct task {
//	string sbj;
//	int ddl;
//	int use;
//}a[18];
//
//bool cmp(task x, task y) {
//	if(x.ddl-x.use != y.ddl-y.use)	return x.ddl-x.use < y.ddl-y.use;
//	else if(x.use != y.use)	return x.use < y.use;
//	else	return x.sbj < y.sbj;
//}
//
//int main() {
//	int T;
//	cin>>T;
//	while(T--) {
//		int n, d, c;
//		string s;
//		cin>>n;
//		for(int i=0; i<n; i++) {
//			cin>>a[i].sbj>>a[i].ddl>>a[i].use;
//		}
//		sort(a, a+n, cmp);
//		int temp = 0;
//		int ans = 0;
//		int now = 0;
//		for(int i=0; i<n; i++) {
//			now += a[i].use;
//			temp = now - a[i].ddl;
////			cout<<"temp: "<<temp<<" now: "<<now<<endl;
//			if(temp <= 0)	temp = 0;
//			ans += temp;
//		}
//		cout<<ans<<endl;
//		for(int i=0; i<n; i++)
//			cout<<a[i].sbj<<endl;
//	}
//	return 0;
//}
