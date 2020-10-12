#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
//�߶��� 
//2020-08-15 10:46:00	Accepted	1754	889MS	28792K	2205 B	G++	
//��Ϊ����������СTLE�ü��� 
int a[2000005];
int tree[5000050];
//δ�Ż��Ŀռ临�Ӷ�Ϊ2N��ʵ��Ӧ��ʱһ�㻹Ҫ��4N����������Խ��

int Max(int x, int y) {
	return x >= y ? x : y;
}

void build_tree(int node, int start, int end) {
	if(start == end) {
		tree[node] = a[start];
	}
	else {
		int mid = (start + end) / 2;
		int left_node  = 2 * node + 1;
		int right_node = 2 * node + 2;
		build_tree(left_node,  start, mid);
		build_tree(right_node, mid+1, end);
		//�������ֵ 
		tree[node] = Max(tree[left_node], tree[right_node]);
	}
}

void update_tree(int node, int start, int end, int idx, int val) {
	if(start == end) {
		a[idx] = val;
		tree[node] = val;
	}
	else {
		int mid = (start + end) / 2;
		int left_node  = 2 * node + 1;
		int right_node = 2 * node + 2;
		if(idx >= start && idx <= mid) {
			update_tree(left_node, start, mid, idx, val);
		}
		else {
			update_tree(right_node, mid+1, end, idx, val);
		}
		tree[node] = Max(tree[left_node], tree[right_node]);
	}
}

int query_tree(int node, int start, int end, int L, int R) {
	//L,R �ǲ�ѯ����
	if(R < start || L > end) {
		return 0;
	} 
	else if(L <= start && R >= end) {
		return tree[node];
	}
	else {
		int mid = (start + end) / 2;
		int left_node  = 2 * node + 1;
		int right_node = 2 * node + 2;
		int max_left  = query_tree(left_node,  start, mid, L, R);
		int max_right = query_tree(right_node, mid+1, end, L, R);
		return Max(max_left, max_right);
	}
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		memset(a, 0, sizeof(a));
		memset(tree, 0, sizeof(tree));
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		build_tree(0, 0, n-1);
//		cout<<"Tree: ";
//		for(int i=0; i<=2*n+2; i++)
//			cout<<tree[i]<<" ";
//		cout<<endl;
		
		char op[3];
		int x, y;
		for(int i=0; i<m; i++) {
			scanf("%s", op);
			scanf("%d%d", &x, &y);
			if(op[0] == 'Q') {  //��ѯ 
				int res = query_tree(0, 0, n-1, x-1, y-1);
				cout<<res<<endl;
			}
			else {  //�޸� 
				update_tree(0, 0, n-1, x-1, y);
//				cout<<" After Modified Tree: ";
//				for(int i=0; i<=2*n+2; i++)
//					cout<<tree[i]<<" ";
//				cout<<endl;
			}
		}
	}
	return 0;
} 
