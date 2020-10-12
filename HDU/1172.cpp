#include <iostream>
using namespace std;
int a[101], b[101], c[101];
int s[4], t[4];
int ans;

bool check(int x, int y){
	int cnt1 = 0, cnt2 = 0;
	int x_ = a[y];
	for(int i=3; i>=0; i--){
		s[i] = x%10;
		x /= 10;
		t[i] = x_%10;
		x_ /= 10;
	}
	for(int i=0; i<4; i++)
		if(s[i] == t[i])	cnt1++;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(s[i] == t[j]){
				cnt2++;
				t[j] = -1;
				break;
			}
		}
	}
	return cnt1 == c[y] && cnt2 == b[y];
}

int main(){
	int n;
	while(cin>>n && n){
		for(int i=0; i<n; i++)
			cin>>a[i]>>b[i]>>c[i];
		int cnt = 0;
		for(int i=1000; i<10000 && cnt<2; ++i){
			int j = 0;
			for(j=0; j<n; j++)
				if(!check(i, j))	break;
			if(j == n){
				cnt++;
				ans = i;
			}
		}
		if(cnt == 1)
			cout<<ans<<endl;
		else
			cout<<"Not sure"<<endl;
	}
	
	return 0;
}
