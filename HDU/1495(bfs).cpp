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
	//���ݻ�Ϊsa�ı��ӵ����ݻ�Ϊsb�ı���,�������ò���a��b����ʼʱΪԭʼ�����п��ֵ������������������Ϻ�Ϊ���Ա��п��ֵ������
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
		//a��b��ˮ
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
		//b��a��ˮ
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
		//a��c��ˮ
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
		//c��a��ˮ
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
		//b��c��ˮ
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
		//c��b��ˮ
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
	//��seeyou������ֻ���������ӣ����ǵ������ֱ���N������M���������ֵ����ΪS��S<101������(����װ��һƿ)
	//��������֮������໥������ (����û�п̶ȵģ��� S==N+M��101��S��0��N��0��M��0)  
	while(~scanf("%d%d%d", &s, &n, &m) && (n+m+s)) {
		if(s & 1)
			printf("NO\n");
		else {
			//init
			for(int i=0; i<=s; i++)
				for(int j=0; j<=n; j++)
					for(int k =0; k<=m; k++)
						vis[i][j][k] = 0;
			//���
			while(!Q.empty()) 	Q.pop();
			//�����ʼ״̬
			//�ֱ������Ϊs n m ��ƿ�����κ�״̬�´��е�Һ��������a b c 
			//��ô��ʼ״̬��Ϊ����ƿ������������ƿ�ӻ�û��Һ�壬Ҳ���� (s, 0, 0, 0) 
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
