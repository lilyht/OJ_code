#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;

double pi = acos(-1.0); //圆周率表示方法 
double s[10005]; 
int N, F;
double sum;

int isOK(double x) {
	int cnt = 0;
	for(int i=1; i<=N; i++) {
		cnt += int(s[i] / x);
	}
	if(cnt >= F+1)
		return 1;
	else
		return 0;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>N>>F;
		int ri;
		memset(s, 0, sizeof(s));
		sum = 0.0;
		for(int i=1; i<=N; i++) {
			cin>>ri;
			s[i] = pi * ri * ri;
			sum += s[i]; 
		}
		
		//二分 
		double l = 0;
		double r = sum * 1.0 / (F + 1);
		double mid;
		
		while(r - l > 0.00001) {  //注意，题目说可以有10^3的差， 那么就需要留出10^-4的精度 
			mid = (l + r) / 2;
			if(isOK(mid)) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		cout<<fixed<<setprecision(4);
		cout<<mid<<endl;
	}
	return 0;
}
