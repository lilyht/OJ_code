#include <iostream>
#include <string.h>
using namespace std;
//素数筛法 
//2020-08-21 13:21:20	Accepted	1164	0MS	1712K	579 B	G++
const int MAXN = 65535;
bool P[MAXN];
int prime[MAXN];

int main() {
	//生成素数表
	int idx = 0;
	memset(P, 0, sizeof(P));
	memset(prime, 0, sizeof(prime));
	for(int i=2; i<MAXN; i++) {
		if(P[i] == false) {
			prime[idx++] = i;
			for(int j=i+i; j<MAXN; j+=i) {  //+i
				P[j] = true;
			}
		}
	} 
	
	int n;
	while(cin>>n) {
		int i=0;
		while(n != 1) {
			if(n % prime[i] == 0) {
				cout<<prime[i];
				n = n / prime[i];
				if(n != 1)
					cout<<"*";
			}
			else
				i++;
		}
		cout<<endl;
	} 
	return 0;
} 
