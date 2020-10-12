#include <iostream>
using namespace std;
//大数卡特兰数
int a[101][101]= {0};  

int main() {
	int i,j,n,k,b[101],len;
	a[1][0] = 1;	//n辆车，对应第一维，a存的值为方案数
	b[1] = len = 1;    //卡特兰数的长度

	for(i = 2; i < 101; i++) {
		for(j = 0; j < len; j++)
			a[i][j] = (4*i-2) * a[i-1][j];
		for(k = j = 0; j < len; j++) {
			a[i][j] += k;
			k = a[i][j] / 10;
			a[i][j] %= 10;
		}
		while (k) {
			a[i][len++] = k%10;
			k /= 10;
		}
		//除法 
		for(j = len-1,k = 0; j >= 0; j--) {	//处理相乘结果
			a[i][j] += k*10;
			k = a[i][j] % (i+1);	//递推公式
			a[i][j] /= (i+1);
		}
		while(!a[i][len-1])        //高位零处理
			len--;
		b[i] = len;
	}
	
	while(cin >> n) {
		for(i = b[n] - 1; i >= 0; i--)
			cout << a[n][i];
		cout << endl;
	}
	
	return 0;
}
