# include<iostream>
# include<cstdio>
# include<string>
# include<cstring>
# include<stack>
using namespace std;
const int MAXN = 16;
const int INF = 0xffffff;
/*  �ο��̳̣�https://www.cnblogs.com/acm-bingzi/p/3278900.html 
 * https://blog.csdn.net/libin56842/article/details/24316493 
 * ��ϸ˵����http://blog.sina.com.cn/s/blog_8e0ea6d50101r17u.html 
 */ 

struct Homework {
	string name;
	int deadline;    //��ֹʱ��
	int time;    //���ʱ��
} data[MAXN];

struct {
	int time;    //��ɸü�����ҵ����ʱ��
	int score;    //��ɸü�����ҵ����ѧ��
	int last;    //��¼��һ��λ��
	int pos;    //��¼��ǰλ��
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
				recent = 1<<i;  ////����iλ
				if(S & recent) {  //���λ��i�ϵ���ҵ����ɵ�
					past = S - recent;    //i��λ��û��ɵ�Ϊǰһ��״̬
//					cout<<"past: "<<past<<endl; 
					reduce = dp[past].time + data[i].time - data[i].deadline;    //��ɸ���ҵ����ѧ�֣�С��0�򲻿�  //��ǰһ��״̬�����״̬�۵����ܷ�
					if(reduce < 0)  //���С�����֤����ǰ���������Ҳ����û�۷�
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
		 //����һ��ջ������������ҵ��˳����һ�����鵹��棬˳���������
		stack<int >path;    //����·��
		recent = endstate - 1;    //1<<n - 1����ʾn��1��2����������ȫ��
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

//̰���㷨����
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
