//#include <iostream>
//#include <iomanip>
//#include <cmath>
//#include <string>
//using namespace std;
//bool flag = true;
//
//int main(){
//	int n, t, total;
//	string s;
//	double d;
//	cin>>n>>d;
//	while(cin>>t){
//		cout<<setw(3)<<t<<": ";
//		flag = 0;
//		total = 0;
//		for(int i=0; i<n; i++){
//			cin>>s;
//			if(s[0] == '-' || s[2] == '-' || s[3] == '-' || s[5] == '-' || s[6] == '-' ){
//				flag = 1;
//				break;
//			}
//			total += (s[0] - '0')*3600 + (s[2] - '0')*600 + (s[3] - '0')*60 + (s[5] - '0')*10 + (s[6] - '0');
//		}
//		if(flag == 1)	cout<<"-"<<endl;
//		else{
////			cout<<"*"<<total<<endl;
////			double avg = total * 1.0 / d;
////			cout<<avg<<endl;
////			int avg_ = (int)((double)total/d+0.5);
//
//			double t1 = total/d;
//            int avg_ = (int)(t1 + 0.5);
//
////			int avg_ = (int)(avg + 0.5);
//			if(avg_/60 != 0 && avg_%60 != 0)
//				cout<<(int)avg_/60<<":"<<(int)avg_%60<<" min/km"<<endl;
//			else if(avg_/60 == 0 && avg_%60 != 0)
//				cout<<"0:"<<(int)avg_%60<<" min/km"<<endl;
//			else if(avg_/60 != 0 && avg_%60 == 0)
//				cout<<(int)avg_/60<<":00"<<" min/km"<<endl;
//			else
//				 cout<<"0:00 min/km"<<endl;
//		}
//	}
//
//	return 0;
//}
#include <stdio.h>
int main() {
	int n;
	double d;
	int num;
	char h,m1,m2,s1,s2;
	scanf("%d",&n);
	scanf("%lf",&d);
	while(scanf("%d",&num)!=EOF) {
		printf("%3d: ",num);
		bool flag=true;
		int sumtime=0;
		for(int i=0; i<n; i++) {
			getchar();
			scanf("%c:%c%c:%c%c",&h,&m1,&m2,&s1,&s2);
			if(h=='-') flag=false;
			if(flag==false)continue;
			sumtime += (h-'0')*3600+((m1-'0')*10+(m2-'0'))*60+(s1-'0')*10+(s2-'0');
		}
		if(flag==false)printf("-\n");
		else {
			double t1=sumtime/d;
			int t2=(int)(t1+0.5);
			printf("%d:%02d min/km\n",t2/60,t2%60);
		}
	}
	return 0;
}
