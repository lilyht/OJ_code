#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
int a[505], b[505], c[505];
long long ab[250050];

int binarysearch(ll x, int l, int r) {
//	cout<<"binarysearch("<<x<<", "<<l<<", "<<r<<")"<<endl;
	if(l > r) {
		return 0;
	}
		
	int mid = (l + r) / 2;  //向下取整 
	if(ab[mid] == x)
		return 1;
	else {
		if(ab[mid] > x)
			binarysearch(x, l, mid-1); 
		else
			binarysearch(x, mid+1, r); 
	}	
}

int main() {
	int L, M, N, S;
	while(cin>>L>>M>>N) {
		//init
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(ab, 0, sizeof(ab));
		//input
		int cnt = 0;
		ll x;
		
		for(int i=0; i<L; i++)	cin>>a[i];
		for(int i=0; i<M; i++)	cin>>b[i];
		for(int i=0; i<N; i++)	cin>>c[i];
		int k = 0;
		for(int i=0; i<L; i++) {
			for(int j=0; j<M; j++) {
				ab[k] = a[i] + b[j];
				k++;
			}
		}
		//sort
		sort(ab, ab+k);
		cin>>S;
		cnt++;
		cout<<"Case "<<cnt<<":"<<endl;
		for(int i=0; i<S; i++) {
			cin>>x;
			//ai + bj + ck = x
			//二分查找
			int j = 0;		
			for(j=0; j<N; j++) {
				if(binarysearch(x - c[j], 0, k-1)) {
					break;
				}
			}
			if(j == N)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
			
		}
	}
	
	return 0;
}

/*
 * 不知道为啥，我的代码就是WA，下面的代码是人家的，Accept的
 * 目测不差啥啊...气死人了，实在找不出来哪里不对 
 */ 

//#include<iostream>
//#include<algorithm>
//#include<stdio.h>
//using namespace std;
//
//int a[505], b[505], c[505];
//int ab[250005];
//
//bool Binary_Search(int a, int l , int R) {
//	//二分
//	if(l > R)
//		return false;
//	int mid = (l + R) / 2;
//    if (ab[mid] == a )
//    	return true;
//   	else if( ab[mid] > a)
//    	Binary_Search( a, l, mid-1);
//   	else
//   		Binary_Search( a, mid+1, R);
//}

//int main() {
// 	int l, n, m;
// 	int i, j, k;
// 	int s, sum, cnt = 1;
// 	while(cin >> l >> n >> m) {
//		for(i = 0; i<l; i++)	cin >> a[i];
// 		for(i = 0; i<n; i++)	cin >> b[i];
// 		for(i = 0; i<m; i++)	cin >> c[i];
//   		
// 		for(k=0, i=0;i<l; i++) {
//  		 	for( j=0; j<n; j++) {
//            	ab[k++] = a[i] + b[j];
//			}
//		}
//		sort(ab, ab + k);
// 		cin >> s;
//		cout << "Case " << cnt++ << ":"<<"\n";
// 		for(i=0; i<s; i++) {
//  			cin >> sum;
//   			for(j=0; j<m; j++)
//    			if (Binary_Search(sum-c[j] , 0 , k-1))  //查找是否有满足的和
//					break;
//			if( j == m)
//				puts("NO"); 
//			else
//    			puts("YES");
//		}
//	}
//	return 0;
//}
