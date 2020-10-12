#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 400;
//2020-09-13 16:58:44	Accepted	1083	1123MS	2032K	792 B	G++
//����ͼ 
int t, p, n;
int mp[MAXN][MAXN];  //����������໥��ϵ
bool mark[MAXN];  //�Ƿ���ҹ�
int rec[MAXN];  //����ƥ���ϵ

bool find(int x) {  //�������x�ţ��γ���ƥ���ѧ�� 
	int i;
	for(i=1; i<=n; i++) {  //����ѧ�� 
		if(!mark[i] && mp[x][i] == 1) {  //���mark������ÿ�β���x֮ǰ��Ҫ��գ�����ע�ⲻ����find��������գ��������ѭ�� 
			mark[i] = 1;  //���Ϊ�ѷ��� 
			if(rec[i] == -1 || find(rec[i])) {  //���ѧ����û��ƥ��������γ̣��������ѧ��ƥ��Ŀγ̻�����ƥ�䵽����ѧ�� 
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
