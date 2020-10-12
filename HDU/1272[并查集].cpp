#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int f[100005];
int vis[100005];
int a, b;
int flag = 0;

void init() {
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<=100000; i++) {
		f[i] = i;
	}
}

int find(int x) {
	if(x != f[x])
        f[x] = find(f[x]);
    return f[x];
}

void Union(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if(fa == fb) {
		flag = 1;
//		printf("-\n");
	}
	else {
		f[fa] = fb;
	}
}

int main() {
	while(~scanf("%d%d", &a, &b)) {
		if(a == -1 && b == -1)	break;
		if(a == 0 && b == 0) {
			printf("Yes\n");
			continue;
		}
		init();
		flag = 0;
		while(1) {
			if(a == 0 && b == 0)
				break;
			Union(a, b);
			vis[a] = 1;
			vis[b] = 1;
            scanf("%d%d", &a, &b);
		}
		if(flag == 1) 
			printf("No\n");
		else {
			int cnt = 0;
			for(int i=0; i<=100000; i++) {
				if(vis[i] == 1 && f[i] == i)
					cnt++;
			}
//			cout<<cnt<<endl;
			if(cnt == 1)  //只有一个集合 
                printf("Yes\n");
            else
            	printf("No\n");
		}
		
	}
	return 0;
} 
