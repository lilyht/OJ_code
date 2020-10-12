#include <iostream>
using namespace std;
const int MAXN = 305;
//http://acm.hdu.edu.cn/showproblem.php?pid=1872
//2020-08-24 10:09:22	Accepted	1872	78MS	1516K	1161 B	G++	
struct node{
	string name;
	int mark;
}a[MAXN], b[MAXN];

void InsertSort(int len) {
	for(int i=0; i<len; i++) {
		int key = a[i].mark;
		string iname = a[i].name;
		int j = i-1;
		while(j >= 0 && a[j].mark < key) {
			a[j+1].mark = a[j].mark;
			a[j+1].name = a[j].name;
			--j;
		}
		a[j+1].mark = key;
		a[j+1].name = iname;
	}
}

void print(int n) {
	for(int i=0; i<n; i++) {
		cout<<a[i].name<<" "<<a[i].mark<<endl;
	}
}

void printb(int n) {
//	cout<<"-----"<<endl;
//	for(int i=0; i<n; i++) {
//		cout<<b[i].name<<" "<<b[i].mark<<endl;
//	}
}

int main() {
	int n;
	while(cin>>n) {
		for(int i=0; i<n; i++)
			cin>>a[i].name>>a[i].mark;
		for(int i=0; i<n; i++)
			cin>>b[i].name>>b[i].mark;
		//≤Â»Î≈≈–Ú
		InsertSort(n);
		int flag = 0;
		for(int i=0; i<n; i++) {
			if(a[i].mark != b[i].mark) {
				cout<<"Error"<<endl;
				print(n); 
				flag = 1;
				break;
			}
			else if(a[i].name != b[i].name) {
				flag = 2;
			}
		}
		if(flag == 1)
			continue;
		else if(flag == 0)
			cout<<"Right"<<endl;
		else if(flag == 2) {
			cout<<"Not Stable"<<endl;
			print(n);
		}
		
	}
	
	return 0;
}
