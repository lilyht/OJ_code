#include <iostream>
using namespace std;
//�������� 
//h(0) = 1, h(1) = 1;
//h(n) = h(0)*h(n-1) + h(1)*h(n-2) + ... + h(n-1)*h(0)  n >= 2
//h(n) = h(n-1) * (4n-2)/(n+1)
long long h[102][200];
//h[i][0]��λ�� 

void catalan(){
	for(int n = 2; n<=20; n++){
		int x = n;
		int c = 4*n - 2;
		int d = n + 1;
		int i;
		//�˷� 
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
//			h[x][i] = c * h[x-1][i];  //��Ϲ�ʽ��һάΪ��������ĵ���
//		for(k = j = 0; j < len; j++) {
//			a[i][j] += k;
//			k = a[i][j] / 10;    //k��Ӧ����ֵ
//			a[i][j] %= 10;
//		}
//		while (k) {		//���һλ�����ƽ���
//			a[i][len++] = k%10;
//			k /= 10;
//		}	
		cout<<"i2 = "<<i<<endl;
		
		//����
		int cf = 0;
		 for(int j=i; j>0; j--){
		 	h[x][j] += cf*10;
		 	cf = h[x][j] % (i+1);	//���ƹ�ʽ
		 	h[x][j] /= d;
		 }
		 while(!h[x][i])        //��λ�㴦��
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
