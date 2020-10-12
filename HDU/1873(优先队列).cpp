#include <iostream>
#include <queue>
using namespace std;
//2020-08-24 10:55:45	Accepted	1873	156MS	1432K	1202 B	G++
struct node{
	int id;
	int rank;
	node(int d, int r): id(d), rank(r) {}
	friend bool operator < (const node& a, const node& b) {  //升序 
		if(a.rank == b.rank)
			return a.id > b.id;
		return a.rank < b.rank;
	}
};

priority_queue<node> q1, q2, q3;

int main() {
	int n, A, B;
	string op;
	while(cin>>n) {
		int cnt = 0;
		//清空优先队列
		while(!q1.empty())	q1.pop();
		while(!q2.empty())	q2.pop();
		while(!q3.empty())	q3.pop();
		
		for(int i=1; i<=n; i++) {
			cin>>op;
			if(op == "IN") {
				cnt++;
				cin>>A>>B;  //一拥有优先级B的病人要求医生A诊治
				if(A == 1)	q1.push(node(cnt, B));
				else if(A == 2)	q2.push(node(cnt, B));
				else	q3.push(node(cnt, B));
			}
			else {
				cin>>A;
				if(A == 1) {
					if(!q1.empty()) {
						cout<<q1.top().id<<endl;
						q1.pop(); 
					}
					else
						cout<<"EMPTY"<<endl;
				}
				else if(A == 2) {
					if(!q2.empty()) {
						cout<<q2.top().id<<endl;
						q2.pop(); 
					}
					else
						cout<<"EMPTY"<<endl;
				}
				else if(A == 3) {
					if(!q3.empty()) {
						cout<<q3.top().id<<endl;
						q3.pop(); 
					}
					else
						cout<<"EMPTY"<<endl;
				}
			}
			
		}
	}
	
	return 0;
} 
