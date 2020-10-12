#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//2020-09-16 08:46:22	Accepted	6886	1575MS	1372K	817 B	G++ 
int a[4][4];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		for(int i=1; i<=3; i++)
			for(int j=1; j<=3; j++)
				scanf("%d",&a[i][j]);
		
		int nm = 0;
		for(int x1=1; x1<=3; x1++)
			for(int y1=1; y1<=3; y1++) {
				bool f=true;
				for(int x2=1; x2<=3; x2++)
					for(int y2=1; y2<=3; y2++) {
						if(x1==x2 || y1==y2)	continue;
						int ans = 0;
						for(int x3=1; x3<=3; x3++)
							for(int y3=1; y3<=3; y3++) {
								if(x3==x1 && y3==y1)	continue;
								if(x3==x2 && y3==y2)	continue;
								if(x3!=x1 && x3!=x2 && y3!=y2 && y3!=y1)
									ans ^= a[x3][y3];
								else
									ans ^= a[x3][y3]-1;
							}
						if(ans==0)	f = false;  //异或值为0，必输 
					}
				if(f)	nm++;
			}
		printf("%d\n", nm);
	}
	return 0;
}
