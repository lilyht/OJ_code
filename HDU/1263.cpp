#include <iostream>
#include <vector>
#include <map>
using namespace std;
//2020-09-14 17:17:27	Accepted	1263	15MS	1452K	636 B	G++
map<string, map<string, int> > m;
//map中元素输出是按字母排序
int main() {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		int num;
		string name, place;
		m.clear();
		for(int i=0; i<n; i++) {
			cin>>name>>place>>num;
			m[place][name] += num;
		}
		for(map<string, map<string, int> >::iterator it=m.begin(); it!=m.end(); it++) {
			cout<<it->first<<endl;
			for(map<string, int>::iterator it2=it->second.begin(); it2!=it->second.end(); it2++) {
				cout<<"   |----"<<it2->first<<"("<<it2->second<<")"<<endl;
			}
		}
		if(t)
			cout<<endl;
	}
	return 0;
}
