#include <iostream>
//#include <stdlib>
#include <stack>
using namespace std;

stack <int> s;

int main(){
	int n;
	cin>>n;
	getchar();  //∂¡»°ªÿ≥µ
	while(n--){
		while(1){
			char c = getchar();
			char ch;
			if(c == ' ' || c == '\n'){
				while(!s.empty()){
					ch = s.top();
					cout<<ch;
					s.pop();
				}
				if(c == '\n')	{
					cout<<endl;
					break;
				}
				else	cout<<" ";
			}
			else{
				s.push(c);
			}
		}
//		getchar();
	}
	
	return 0;
}
