#include <iostream>
using namespace std;
//卡特兰数 
//h(0) = 1, h(1) = 1;
//h(n) = h(0)*h(n-1) + h(1)*h(n-2) + ... + h(n-1)*h(0)  n >= 2
//h(n) = h(n-1) * (4n-2)/(n+1)
long long h[102][200];
//h[i][0]存位数 

void catalan(){
	for(int n = 2; n<=20; n++){
		int x = n;
		int c = 4*n - 2;
		int d = n + 1;
		int i;
		//乘法 
//		for(i=1; i<=h[x-1][0]; i++){
//			h[x][i] = h[x-1][i]*c + h[x][i];
//			h[x][i+1] =	h[x][i]/10;
//			h[x][i] %= 10;
//		}
//		i = i - 1;
//		while(h[x][i] > 9){
//			h[x][i+1] =	h[x][i]/10;
//			h[x][i] %= 10;
//			i++;
//		}
//		for(i=1; i < h[x-1][0]; i++)
//			h[x][i] = c * h[x-1][i];  //组合公式，一维为控制数组的递推
//		for(k = j = 0; j < len; j++) {
//			a[i][j] += k;
//			k = a[i][j] / 10;    //k对应进阶值
//			a[i][j] %= 10;
//		}
//		while (k) {		//最后一位，控制进阶
//			a[i][len++] = k%10;
//			k /= 10;
//		}	
		cout<<"i2 = "<<i<<endl;
		
		//除法
		int cf = 0;
		 for(int j=i; j>0; j--){
		 	h[x][j] += cf*10;
		 	cf = h[x][j] % (i+1);	//递推公式
		 	h[x][j] /= d;
		 }
		 while(!h[x][i])        //高位零处理
			i--;
		h[x][0] = i;

	}
}

void printres(int t){
	for(int i=h[t][0]; i>0; i--){
		cout<<h[t][i];
	}
	cout<<endl;
}

int main(){
	int n;
	h[0][1] = h[1][1] = 1;
	h[0][0] = h[1][0] = 1;
	catalan();
	while(cin>>n){
		printres(n); 
	}
	
	return 0;
}
