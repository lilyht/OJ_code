#include <iostream>
#include <queue>
using namespace std;

int n, m, s;
bool vis[105][105][105];

struct node{
	int a, b, c;
	int t;
};
queue<node> Q;

void AtoB(int &a, int sa, int &b, int sb) {
	//由容积为sa的杯子倒往容积为sb的杯子,其中引用参数a和b，初始时为原始杯子中可乐的体积，当函数调用完毕后，为各自杯中可乐的新体积
	if(sb - b >= a) {
		b += a;
		a = 0;
	}
	else {
		a -= sb - b;
		b = sb;
	}
}

int bfs() {
	while(!Q.empty()) {
		node cur = Q.front();
		Q.pop();
		int a, b, c;
		//a向b倒水
		a = cur.a;
		b = cur.b;
		c = cur.c;
		AtoB(a, s, b, n);
		if(vis[a][b][c] == 0) {
			vis[a][b][c] = 1;
			node tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = cur.t + 1;
			if(a == s/2 && b == s/2)	return tmp.t;
			if(a == s/2 && c == s/2)	return tmp.t;
			if(c == s/2 && b == s/2)	return tmp.t;
			Q.push(tmp);
		}
		//b向a倒水
		a = cur.a;
		b = cur.b;
		c = cur.c;
		AtoB(b, n, a, s);
		if(vis[a][b][c] == 0) {
			vis[a][b][c] = 1;
			node tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = cur.t + 1;
			if(a == s/2 && b == s/2)	return tmp.t;
			if(a == s/2 && c == s/2)	return tmp.t;
			if(c == s/2 && b == s/2)	return tmp.t;
			Q.push(tmp);
		}
		//a向c倒水
		a = cur.a;
		b = cur.b;
		c = cur.c;
		AtoB(a, s, c, m);
		if(vis[a][b][c] == 0) {
			vis[a][b][c] = 1;
			node tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = cur.t + 1;
			if(a == s/2 && b == s/2)	return tmp.t;
			if(a == s/2 && c == s/2)	return tmp.t;
			if(c == s/2 && b == s/2)	return tmp.t;
			Q.push(tmp);
		}
		//c向a倒水
		a = cur.a;
		b = cur.b;
		c = cur.c;
		AtoB(c, m, a, s);
		if(vis[a][b][c] == 0) {
			vis[a][b][c] = 1;
			node tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = cur.t + 1;
			if(a == s/2 && b == s/2)	return tmp.t;
			if(a == s/2 && c == s/2)	return tmp.t;
			if(c == s/2 && b == s/2)	return tmp.t;
			Q.push(tmp);
		}
		//b向c倒水
		a = cur.a;
		b = cur.b;
		c = cur.c;
		AtoB(b, n, c, m);
		if(vis[a][b][c] == 0) {
			vis[a][b][c] = 1;
			node tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = cur.t + 1;
			if(a == s/2 && b == s/2)	return tmp.t;
			if(a == s/2 && c == s/2)	return tmp.t;
			if(c == s/2 && b == s/2)	return tmp.t;
			Q.push(tmp);
		}
		//c向b倒水
		a = cur.a;
		b = cur.b;
		c = cur.c;
		AtoB(c, m, b, n);
		if(vis[a][b][c] == 0) {
			vis[a][b][c] = 1;
			node tmp;
			tmp.a = a;
			tmp.b = b;
			tmp.c = c;
			tmp.t = cur.t + 1;
			if(a == s/2 && b == s/2)	return tmp.t;
			if(a == s/2 && c == s/2)	return tmp.t;
			if(c == s/2 && b == s/2)	return tmp.t;
			Q.push(tmp);
		}
	//a s | b n | c m
	}
	return -1;
}

int main() {
	//但seeyou的手中只有两个杯子，它们的容量分别是N毫升和M毫升，可乐的体积为S（S<101）毫升(正好装满一瓶)
	//它们三个之间可以相互倒可乐 (都是没有刻度的，且 S==N+M，101＞S＞0，N＞0，M＞0)  
	while(~scanf("%d%d%d", &s, &n, &m) && (n+m+s)) {
		if(s & 1)
			printf("NO\n");
		else {
			//init
			for(int i=0; i<=s; i++)
				for(int j=0; j<=n; j++)
					for(int k =0; k<=m; k++)
						vis[i][j][k] = 0;
			//清空
			while(!Q.empty()) 	Q.pop();
			//加入初始状态
			//分别把容量为s n m 的瓶子中任何状态下存有的液体量记做a b c 
			//那么初始状态即为可乐瓶满，其余两个瓶子还没有液体，也就是 (s, 0, 0, 0) 
			node st;
			st.a = s;
			st.b = st.c = st.t = 0; 
			Q.push(st);
			vis[s][0][0] = 1;
			
			int res = bfs();
			if(res == -1)
				printf("NO\n");
			else
				printf("%d\n", res);
		}
	}
	return 0;
}
