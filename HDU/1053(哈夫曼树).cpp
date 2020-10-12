#include <iostream>
#include <string.h>
#include <queue>
#include <iomanip>
using namespace std;
//2020-09-12 20:07:55	Accepted	1053	0MS	2080K	844B	G++
int a[100010];
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	string s;
	while(cin>>s) {
		if(s == "END")	break;
		int len = s.length();
		memset(a, 0, sizeof(a));
		for(int i=0; i<len; i++) {
			if(s[i] == '_')	a[0]++;
			else	a[s[i] - 'A' + 1]++;
		}
		while(!q.empty())	q.pop();
		for(int i=0; i<28; i++)
			if(a[i])	q.push(a[i]);
		int sum = 0;
		if(q.size() == 1) {
			sum = len;
		}
		else {
			while(!q.empty()) {
				int tmp1 = q.top();
				q.pop();
				if(q.empty())	break;
				int tmp2 = q.top();
				q.pop();
				int newnode = tmp1 + tmp2;
				q.push(newnode);
				sum += newnode;
			}
		}
		cout<<8 * len<<" "<<sum<<" ";
		double ratio = 8.0 * len / sum;
		cout<<fixed<<setprecision(1)<<ratio<<endl;
	}
	return 0;
}
