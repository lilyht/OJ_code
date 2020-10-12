#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int MAXN = 100005;
//2020-08-25 22:59:02	Accepted	1116	1076MS	2188K	1601 B	G++
int f[MAXN];
int indegree[MAXN];
int outdegree[MAXN];
int flag[2] = {0, 0};
bool vis[27];

int find(int x) {
	if(x == f[x])	return x;
	return f[x] = find(f[x]);
}

void Union(int u, int v) {
	int fu = find(u);
	int fv = find(v);
	if(fu != fv)
		f[fu] = fv;
}

int main() {
	int t, n;
	string word;
	cin>>t;
	while(t--) {
		cin>>n; 
		for(int i=0; i<26; i++)	f[i] = i;
		memset(indegree, 0, sizeof(indegree));
		memset(outdegree, 0, sizeof(outdegree));
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; i++) {
			cin>>word;
			int u = (int)word[0] - 'a';
			int v= (int)word[word.length()-1] - 'a';
//			cout<<u<<" "<<v<<endl;
			vis[u] = vis[v] = 1;
			outdegree[u]++;
			indegree[v]++;
			Union(u, v);
		}
		//判断是否连通
		int cnt = 0; 
		int num = 0;
		for(int i=0; i<26; i++)
			if(f[i] == i && vis[i])
				cnt++;
		if(cnt == 1) {
			//连通 
			for(int j=0; j<26; j++) {
				if(vis[j] && indegree[j] != outdegree[j])	{
					flag[num] = j;
					num++;  //出度入度不相等的节点数 
				}
			}
			if(num == 0)
				cout<<"Ordering is possible."<<endl;
			else if(num == 2) {
				int cha1 = indegree[flag[0]] - outdegree[flag[0]];
				int cha2 = indegree[flag[1]] - outdegree[flag[1]];
				if((cha1 == 1 && cha2 == -1) || (cha1 == -1 && cha2 == 1)) {
					cout<<"Ordering is possible."<<endl;
				}
				else
					cout<<"The door cannot be opened."<<endl;
			} 
			else
				cout<<"The door cannot be opened."<<endl;
		}
		else {
			cout<<"The door cannot be opened."<<endl;
		} 
	} 
	
	return 0;
} 
