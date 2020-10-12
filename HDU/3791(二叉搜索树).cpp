#include <iostream>
#include <string.h>
using namespace std;
//2020-08-12 18:07:51	Accepted	3791	15MS	1404K	1783 B	G++
//�ж��������Ƿ�Ϊͬһ��������������

//���Ƕ�������������й����������������������ǽ���ǰ�������ı�����
//���αȽ����α�������Ƿ���ͬ������ͬ��˵�����ö�����������ͬ������ͬ�� 

string s, tmp;
int loc = 0;
int size1, size2;
int *size;  //��ǰ���ڱ����ַ������ַ�����
char ans1[25];
char ans2[25];
char *ans;  //��ǰ���ڱ����ַ���

struct Node{
	Node * lchild;
	Node * rchild;
	int c;
}Tree[1005];

Node* create() {
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

void postOrder(Node *T) {  //������� 
	if(T->lchild != NULL)	postOrder(T->lchild);
	if(T->rchild != NULL)	postOrder(T->rchild);
	ans[(*size)++]  = T->c + '0';  //������е��ַ��������ڱ�����ַ�����
}

void inOrder(Node *T) {  //������� 
	if(T->lchild != NULL)	postOrder(T->lchild);
	ans[(*size)++]  = T->c + '0';
	if(T->rchild != NULL)	postOrder(T->rchild);
}

Node *Insert(Node *T, int x) {  //��������� 
	if(T == NULL) {
		T = create();
		T->c = x;
		return T;
	}
	else if(x < T->c) {  //С�ڸ��ڵ� �����뵽������
		T->lchild = Insert(T->lchild, x);
	}
	else if(x > T->c) {  //���ڣ����뵽������ 
		T->rchild = Insert(T->rchild, x);
	}
	return T;
}

int main() {
	int n;
	while(cin>>n && n) {
		loc = 0;
		cin>>s;
		Node *T = NULL;
		for(int i=0; i<s.length(); i++)	T = Insert(T, s[i] - '0');
		size1 = 0;  //�����ڵ�һ���ַ����е��ַ���ʼ��Ϊ0
		ans = ans1;  //�����ڱ����ַ����趨Ϊ��һ���ַ���
		size = &size1;  //�����ڱ����ַ����е��ַ�����ָ��ָ��size1
		postOrder(T);
		inOrder(T);
		ans1[size1] = 0;  //���һ���ַ��������һ���ַ�����ӿ��ַ�,����ʹ���ַ�������
		
		while(n--) {
			cin>>tmp;
			Node *T2 = NULL;
			for(int i=0; tmp[i] != 0; i++) {
				T2 = Insert(T2, tmp[i] - '0');
			} 
			size2 = 0;
			ans = ans2;
			size = &size2;  //���ڱ����ַ������ַ�����ָ��ָ��size2
			postOrder(T2);
			inOrder(T2);
			ans2[size2] = 0;
//			cout<<"ans1: "<<ans1<<endl;
//			cout<<"ans2: "<<ans2<<endl;
			if(strcmp(ans1, ans2) == 0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	} 
	return 0;
}
