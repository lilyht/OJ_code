#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100010;

int randPartition(int A[], int left, int right) {
	int p = round(1.0*rand() / RAND_MAX*(right - left) + left);
	swap(A[p], A[left]);
	int temp = A[left];
	while(left < right) {
		while(left < right && A[right] > temp)	right--;
		A[left] = A[right];
		while(left < right && A[right] <= temp)	left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}
s
int randSelect(int A[], int left, int right, int K) {
	if(left == right)	return A[left];
	int p = randPartition(A, left, right);
	int M = p - left + 1;
	if(K == M) {
		return A[p];
	}
	if(K < M) {
		return randSelect(A, left, p-1, K);
	}
	else {
		return randSelect(A, p+1, right, K-M);
	}
} 

int main() {
	srand((unsigned)time(NULL));
	int A[10] = {3, 4, 1, 7, 2, 5, 6, 9, 8, 10};
	int n = 10;
	int x = randSelect(A, 0, n-1, 2);  //第二大的数字 
	cout<<x<<endl;
	
	return 0;
} 
