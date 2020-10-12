#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAX 99999999999999.0
using namespace std;
//分治 
struct node {
	double x, y;
} nd[100005], ndx[100005];

bool cmp(node a, node b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool cmpy(node a, node b) {
	return a.y < b.y;
}

double dist(node a, node b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double solve(int ld, int rd) {
	if(ld == rd) return MAX;
	if(ld + 1 == rd) return dist(nd[ld], nd[rd]);  //集合中只有两个点的时候返回这两点间距离 
	int mid = (ld+rd) / 2;  //分治 
	double ans = min(solve(ld, mid), solve(mid+1, rd));
	int len = 0;
	for(int i = mid; i>=ld; --i)  //将mid附近一个可能出现最短距离的范围中的点拿出来另作讨论 
		if(nd[mid].x - nd[i].x <= ans)
			ndx[len++] = nd[i];
		else break;
	for(int i=mid+1; i<=rd; ++i)
		if(nd[i].x - nd[mid].x <= ans)
			ndx[len++] = nd[i];
		else break;

	sort(ndx, ndx+len, cmpy);
	for(int i=0; i<len-1; ++i)
		for(int j=i+1; j<len; ++j)
			if(ndx[j].y - ndx[i].y >= ans) break;  //当两点间纵坐标距离已经超过d则可以直接进入下一次循环  
			else ans = min(ans, dist(ndx[i], ndx[j]));
	return ans;
}

int main() {
	int n;
	while(scanf("%d", &n) && n) {
		for(int i=0; i<n; ++i)
			scanf("%lf%lf", &nd[i].x, &nd[i].y);
		sort(nd, nd+n, cmp);
		printf("%.2lf\n", solve(0, n-1)/2.0);
	}
	return 0;
}
