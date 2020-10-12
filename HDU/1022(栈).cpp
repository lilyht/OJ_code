#include <iostream>
#include <stack>
#include <string> 
#include <cstring>
using namespace std;
int f[20];

int main(){
	int n;
	string o1, o2;
	while(cin>>n){
		cin>>o1>>o2;
		stack <char> s;
		memset(f, 0, sizeof(f));
		int j = 0, step = 0;
		for(int i=0; i<n; i++){
			s.push(o1[i]);
			f[step++] = 1;
			while(!s.empty() && s.top() == o2[j]){
				f[step++] = 2;
				s.pop();
				j++;
			}
		}
		if(j == n){
			cout<<"Yes."<<endl;
			for(int i=0; i<step; i++){
				if(f[i] == 1)	cout<<"in"<<endl;
				else if(f[i] == 2)	cout<<"out"<<endl;
			}
		}
		else
			cout<<"No."<<endl;
		cout<<"FINISH"<<endl;
	}
	
	return 0;
}
