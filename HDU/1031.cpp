#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int p[1000];

struct node{
	int index;
	double sum;
}a[1000];
int b[1000];

bool cmp(node x, node y){
	if(x.sum != y.sum)	return x.sum > y.sum;
	return x.index > y.index;
}

int main(){
	int n, m, k;
	double o;
	while(cin>>n>>m>>k){
		memset(a, 0, sizeof(a));
		for(int i=0; i<n; i++){
			for(int j=1; j<=m; j++){
				a[j].index = j;
				cin>>o;
				a[j].sum += o;
			}
		}
		sort(a+1, a+m+1, cmp);
		//test
//		for(int i=1; i<=m; i++){
//			cout<<a[i].sum <<" : "<<a[i].index<<endl;
//		}
		for(int i=1; i<=k; i++){
			b[i] = a[i].index;
		}
		sort(b+1, b+k+1);
		for(int i=k; i>1; i--)
			cout<<b[i]<<" ";
		cout<<b[1]<<endl;
	}
	
	return 0;
}
