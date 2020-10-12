/**
hdu1043 bfs
题目大意：类似一个九宫格问题，给定一个3*3的棋盘，有1~8个数字，一个x。给定初始位置状态，最终到达同一指定状态，x棋子可以和其上下左右的棋子进行交换顺序，求出一种给定的合法序列
          从初始状态可以到达给定状态
解题思路：基本的方法是利用康拓展开记录状态，从初始状态到给定状态进行bfs搜索。但是这样写有多少组输入就要进行多少次bfs比较费时。因为题目给定的是同一个目标状态，所以我们进行倒着搜
          搜索出所有的状态，这样只进行一次bfs就可以了
*/
#include <string.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
const int maxn=1e6+5;	// 9！=362880，用10的6次方足够了
const int INF=0x3f3f3f3f;
 
struct note{
    char s[3][3];
    int x,y;	// x所在的坐标
    int can;	// 康拓展开序号
};
 
int father[maxn],path[maxn],vis[maxn]; // father记录上一个序列，path记录移动方向，vis记录序列状态是否出现过
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
int fac[10];
 
// 求某个排列的康拓序号，用来判断是否移动到这种情况过，用于广搜的剪枝条件
int canton(char s[3][3]){
	// 求1到9的阶乘
    fac[0]=1;
    fac[1]=1;
    for(int i=2; i<10; i++){
        fac[i] = fac[i-1]*i;
    }

    // 因为这题用的是字符输入，字符交换可以用swap函数，比较方便，所以先把二维字符数组对应到一个一维整型数组上
    int a[9];
    int cur=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            a[cur++]=s[i][j]-'0';
        }
    }

    /* 
    	计算康拓展开的序号:
	    eq：45132 
	    4后面比4小的数有3个，4后面4个数的排列有4！个，所以长度为5的数字序列中比45132小的数有3*4！个
	    5后面比5小的数有3个，5后面3个数的排列有3！个，所以长度为4的数字序列中比5132小的数有3*3！个
	    1后面比1小的数有0个，1后面2个数的排列有2！个，所以长度为3的数字序列中比132小的数有0*2！个
	    3后面比3小的数有1个，3后面1个数的排列有1！个，所以长度为5的数字序列中比32小的数有1*1！个
	    2后面比2小的数有0个，2后面0个数的排列有0！个，所以长度为1的数字序列中比2小的数有0*0！个
	    所以在0~45132这些数中，45132的康拓展开序号是3*4！+3*3！+0*2！+1*1！+0*0！+1（+1是因为序号是从1开始的，数是从0开始的）
	    也就说康拓展开其实是数从小到大排序的序号
	*/
    int ans=0;
    for(int i=0; i<9; i++){
        int cnt=0;
        for(int j=i+1; j<9; j++){
            if(a[j]<a[i])cnt++;
        }
        ans+=cnt*fac[8-i];
    }
    return ans;
}
 
// 从最终的状态倒回头，看走到任何能走到的状态最少需要多少移动，同时记录上一个状态以及移动的方向
void bfs(note ss){
    queue<note>q;
    int ca = canton(ss.s);
    vis[ca] = 1;
    father[ca] = -2;
    ss.can = ca;
    q.push(ss);

    while(!q.empty()){
        note st = q.front(),en;
        q.pop();

        for(int i=0; i<4; i++){
            int x = st.x+dx[i];
            int y = st.y+dy[i];

            // 在范围内可以移动
            if(x>=0&&x<3&&y>=0&&y<3){
            	// 移动
                en = st;
                swap(en.s[x][y],en.s[st.x][st.y]);
                // 判断移动后的序列是否出现过
                int t = canton(en.s);
                if(!vis[t]){
                    vis[t] = 1;
                    en.x = x;
                    en.y = y;
                    en.can = t;
                    q.push(en);
                    // 记录上一个序列，和上一个序列到当前序列的走法，用于之后的输出
                    father[t] = st.can;
                    path[t] = i;
                }
            }
        }
    }
}
 
// 逆序打印走的过程
void print(int x){
    if(father[x]==-2)return;
    int t = path[x];
    if(t==0)putchar('d');
    else if(t==1)putchar('u');
    else if(t==2)putchar('r');
    else putchar('l');
    print(father[x]);
}
 
int main(){
    memset(vis,0,sizeof(vis));
    memset(father,-1,sizeof(father));

    // 先创建终止状态的结点，然后广搜找出所有能达到的序列及对应的父状态，移动方向等信息
    note s;
    int cnt=1;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            s.s[i][j]=cnt+'0';
            cnt++;
        }
    }
    s.s[2][2] = '0';
    s.x = s.y = 2;
    bfs(s);

    char ss[3][3];
    char sss[100];
    while(gets(sss)!=NULL){
    	// 输入数据
        int cur=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                while(sss[cur]==' '&&sss[cur]!='\0') cur++;
                if(sss[cur]<='9'&&sss[cur]>='0')
                    ss[i][j] = sss[cur++];
                else if(sss[cur]=='x'){
                    ss[i][j] = '0';
                    cur++;
                }
            }
        }

        // 判断结果
        int sta = canton(ss);
        if(father[sta]==-1)
            printf("unsolvable");
        else
            print(sta);
        cout<<endl;
    }
    return 0;
}