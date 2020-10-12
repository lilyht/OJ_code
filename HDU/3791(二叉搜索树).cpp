#include <iostream>
#include <string.h>
using namespace std;
//2020-08-12 18:07:51	Accepted	3791	15MS	1404K	1783 B	G++
//判断两序列是否为同一二叉搜索树序列

//我们对输入的数字序列构建二叉排序树，并对它们进行前序和中序的遍历，
//依次比较两次遍历结果是否相同，若相同则说明两棵二叉排序树相同，否则不同。 

string s, tmp;
int loc = 0;
int size1, size2;
int *size;  //当前正在保存字符串中字符个数
char ans1[25];
char ans2[25];
char *ans;  //当前正在保存字符串

struct Node{
	Node * lchild;
	Node * rchild;
	int c;
}Tree[1005];

Node* create() {
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}

void postOrder(Node *T) {  //后序遍历 
	if(T->lchild != NULL)	postOrder(T->lchild);
	if(T->rchild != NULL)	postOrder(T->rchild);
	ans[(*size)++]  = T->c + '0';  //将结点中的字符放入正在保存的字符串中
}

void inOrder(Node *T) {  //中序遍历 
	if(T->lchild != NULL)	postOrder(T->lchild);
	ans[(*size)++]  = T->c + '0';
	if(T->rchild != NULL)	postOrder(T->rchild);
}

Node *Insert(Node *T, int x) {  //插入二叉树 
	if(T == NULL) {
		T = create();
		T->c = x;
		return T;
	}
	else if(x < T->c) {  //小于根节点 ，插入到右子树
		T->lchild = Insert(T->lchild, x);
	}
	else if(x > T->c) {  //大于，插入到右子树 
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
		size1 = 0;  //保存在第一个字符串中的字符初始化为0
		ans = ans1;  //将正在保存字符串设定为第一个字符串
		size = &size1;  //将正在保存字符串中的字符个数指针指向size1
		postOrder(T);
		inOrder(T);
		ans1[size1] = 0;  //向第一个字符串的最后一个字符后添加空字符,方便使用字符串函数
		
		while(n--) {
			cin>>tmp;
			Node *T2 = NULL;
			for(int i=0; tmp[i] != 0; i++) {
				T2 = Insert(T2, tmp[i] - '0');
			} 
			size2 = 0;
			ans = ans2;
			size = &size2;  //正在保存字符串中字符数量指针指向size2
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
