#include <iostream>
using namespace std;
//������������
int a[101][101]= {0};  

int main() {
	int i,j,n,k,b[101],len;
	a[1][0] = 1;	//n��������Ӧ��һά��a���ֵΪ������
	b[1] = len = 1;    //���������ĳ���

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
		//���� 
		for(j = len-1,k = 0; j >= 0; j--) {	//������˽��
			a[i][j] += k*10;
			k = a[i][j] % (i+1);	//���ƹ�ʽ
			a[i][j] /= (i+1);
		}
		while(!a[i][len-1])        //��λ�㴦��
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
