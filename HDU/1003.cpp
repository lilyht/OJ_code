//wrong answer
//#include <iostream>
//#include <string.h>
//using namespace std;
//int a[100005];
//int maxsum, sum, cursum, s, start, e, ende;
//
//int main(){
//	int t, n, cnt;
//	cin>>t;
//	while(t--){
//		cin>>n;
//		cnt++;
//		maxsum = -10000;
//		sum = cursum = 0;
//		s = e = 1;
//		memset(a, 0, sizeof(a));
//		for(int i=1; i<=n; i++)	cin>>a[i];
//		for(int i=1; i<=n; i++){
//			if(sum >= 0){
//				cursum = sum + a[i];
//				e = i;
//			}
//			else{
//				cursum = a[i];
//				s = e = i;
//			}
//			if(maxsum < cursum){
//				maxsum = cursum;
//				start = s;
//				ende = e;
//			}
//			sum = cursum;
//		}
//		cout<<"Case "<<cnt<<":"<<endl;
//		cout<<maxsum<<" "<<start<<" "<<ende<<endl;
//		if(t != 0)	cout<<endl;
//	}
//	
//	
//	return 0;
//} 
//31ms
#include <cstdio>
using namespace std;
int a[100005];
int n,t,kase;

int main(){
	scanf("%d",&t);
    while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i] += a[i-1];
		}
		int s=0, e=0, minn=0, ans=-0x7fffffff;
		for(int i=1,j=0; i<=n; i++){
			if(a[i]-minn > ans)
				ans = a[i] - minn, s=j, e=i;
			if(minn > a[i]){
				minn = a[i];
				j = i;
			}
		}
		printf("Case %d:\n", ++kase);
		printf("%d %d %d\n", ans, ++s, e);
		if(t != 0)    printf("\n");
    }
	return 0;
}
