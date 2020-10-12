#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};
int map[105][105], flag[105][105], c[105][105];
int n, m;
int temp;

struct node {
	int x, y;
	int step;
	friend bool operator < (node n1, node n2) {
		return n2.step < n1.step;
	}
};

int judge(int x,int y) {
	if(x<0 || x>=n || y<0 || y>=m)
		return 1;
	if(map[x][y] == -1)
		return 1;
	return 0;
}

int BFS() {
	priority_queue <node> q;
	node cur,next;
	int i;
	cur.x = 0;
	cur.y = 0;
	cur.step = 0;
	map[0][0] = -1;
	q.push(cur);
	while(!q.empty()) {
		cur = q.top();
		q.pop();
		if(cur.x == n-1 && cur.y == m-1){
			printf("********************************\n");
			return cur.step;
		}
		for(i=0; i<4; i++) {
			next.x = cur.x + dx[i];
			next.y = cur.y + dy[i];
			if(judge(next.x,next.y))
				continue;
			next.step = cur.step + 1 + map[next.x][next.y];
			flag[next.x][next.y] = i + 1;
			map[next.x][next.y] = -1;
			q.push(next);
		}
	}
	return -1;
}

void fun(int x, int y) {
	int a, b;
//	if(flag[x][y] == 0)
//		return;
	if(x == 0 && y == 0)	return;
	a = x - dx[flag[x][y]-1];
	b = y - dy[flag[x][y]-1];
	
	printf("%ds:(%d,%d)->(%d,%d)\n", temp++, a, b, x, y);
	while(c[x][y]--)
		printf("%ds:FIGHT AT (%d,%d)\n", temp++, x, y);
	fun(a, b);
}

int main() {
	char str;
	int ans;
	n = m = 0;
	while(scanf("%d%d", &n, &m) != EOF) {
		printf("n = %d, m = %d\n", n, m);
		memset(map, 0, sizeof(map));
		memset(flag, 0, sizeof(flag));
		memset(c, 0, sizeof(c));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				scanf("%c", &str);
//				printf("%c ", str);
				if(str == '.')
					map[i][j] = 0;
				else if(str == 'X')
					map[i][j] = -1;
				else
					map[i][j] = c[i][j] = str - '0';
			}
		}
		//test
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		ans = BFS();
		if(ans == -1)
			printf("God please help our poor hero.\n");
		else {
			printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
			temp = 1;
//			fun(n-1,m-1);
		}
		printf("FINISH\n");
	}
	
	return 0;
}
