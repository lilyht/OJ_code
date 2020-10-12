#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;

double pi = acos(-1.0); //Բ���ʱ�ʾ���� 
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
		
		//���� 
		double l = 0;
		double r = sum * 1.0 / (F + 1);
		double mid;
		
		while(r - l > 0.00001) {  //ע�⣬��Ŀ˵������10^3�Ĳ ��ô����Ҫ����10^-4�ľ��� 
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
