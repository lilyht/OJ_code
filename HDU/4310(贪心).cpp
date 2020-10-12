#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 24;
//2020-09-16 22:58:51	Accepted	4310	31MS	1404K	705 B	G++
//��̰�Ľ����Ѫ���ٹ����ߵ�Ҫ������������ DPS/HP ��Ϊ�������򣬼������еĵ���

struct node{
	int DPS;
	int HP;
	int stime;
	double c;
}a[MAXN];

bool cmp(node x, node y) {
//	if(x.DPS != y.DPS)	return x.DPS > y.DPS;
//	else	return x.HP < y.HP;
	return x.c > y.c;
}

int main() {
	int n;
	while(cin>>n) {
		for(int i=0; i<n; i++) {
			cin>>a[i].DPS>>a[i].HP;
			a[i].c = a[i].DPS * 1.0 / a[i].HP;
		}
		sort(a, a+n, cmp);
		for(int i=0; i<n; i++) {
			a[i].stime = a[i-1].stime + a[i].HP;
		}
		int ans = 0;
//		cout<<"HP  DPS   TIME"<<endl;
		for(int i=0; i<n; i++) {
			//cout<<a[i].HP<<"   "<<a[i].DPS<<"  "<<a[i].stime<<endl;
			ans += a[i].stime * a[i].DPS;
		}
		cout<<ans<<endl;
	}
	return 0;
}
