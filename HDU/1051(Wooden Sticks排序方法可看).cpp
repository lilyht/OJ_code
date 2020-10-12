#include <iostream>
#include <cstring>
#include <algorithm>
//ºÃ·½·¨£¡£¡£¡ 
using namespace std;
int n, l, w;

struct node{
	int l, w;
	bool flag;
}p[5002];

bool cmp(node x, node y){
	if(x.l != y.l)	return x.l < y.l;
	return x.w < y.w;
}

void find(int i){
	int k = i;
	for(int j=i+1; j<n; j++){
		if(p[j].flag == 0){
			if(p[j].l >= p[k].l && p[j].w >= p[k].w){
				p[j].flag = 1;
				k = j;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int ans = 0;
		memset(p, 0, sizeof(p));
		for(int i=0; i<n; i++){
			cin>>p[i].l>>p[i].w;
			p[i].flag = 0;
		}
		sort(p, p+n, cmp);
		//test
//		for(int i=0; i<n; i++){
//			cout<<p[i].l<<" "<<p[i].w<<" ";
//		}
//		cout<<endl;
		int l_, w_;
		for(int i=0; i<n; i++){
			if(p[i].flag == 0){
				p[i].flag = 1;
				ans++;
				find(i);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
