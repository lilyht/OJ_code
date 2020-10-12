#include <iostream>
#include <string>
using namespace std;

int main(){
	string s, t;
	while(cin>>s){
		if(s == "ENDOFINPUT")	break;
		getchar();
		getline(cin, t);
		cin>>s;
		
		int len = t.length();
		for(int i=0; i<len; i++){
			if(t[i] > 'E' && t[i] <= 'Z'){
				t[i] = t[i] - 5;
			}
			else if(t[i] >= 'A' && t[i] <= 'E'){
				t[i] = t[i] + 21;
			}
			else
				t[i] = t[i];
		}
		for(int i=0; i<len; i++){
			cout<<t[i];
		}
		cout<<endl;
	
	}
	
	return 0;
}
