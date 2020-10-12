#include <iostream>
#include <string.h>
using namespace std;

int a[8];
int ans[9];
int kong[9];
bool vis[8];
//int cnt = 0;
//注意：这个cnt去掉了答案再本地样例都不对了，但是提交还是正确的 ，而实际上这个cnt并没有什么用啊？奇怪了 
int num = 0;
int mp[8][8] = {{0, 1, 1, 1, 0, 0, 0, 0}, 
                {1, 0, 1, 0, 1, 1, 0, 0},
                {1, 1, 0, 1, 1, 1, 1, 0},
                {1, 0, 1, 0, 0, 1, 1, 0},
                {0, 1, 1, 0, 0, 1, 0, 1},
                {0, 1, 1, 1, 1, 0, 1, 1},
                {0, 0, 1, 1, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 1, 1, 0}};

int ABS(int x) {
    if (x >= 0)  
        return x;
    return -x;
}

bool isok() {
    int l = 0;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++) 
            if(mp[i][j] && ABS(a[i] - a[j]) == 1)
                return false;
    return true;
}

void dfs(int x) {
    if(x == 8 && isok()) {
        num++;
        for(int i=0; i<8; i++)
            ans[i] = a[i];
    }
    if(num > 1) {
        return;
    }
    if(a[x] != 0)
        dfs(x+1);
    for(int j=1; j<=8; j++) {
        if(!vis[j]) {
            a[x] = j;
            vis[j] = 1;
            dfs(x+1);
            a[x] = 0;
            vis[j] = 0;
        }
    }
}

int main() {
    int t;
    cin>>t;
    int idx;
    int kse = 1;
    while(t--) {
        memset(vis, 0, sizeof(vis));
        memset(ans, 0, sizeof(ans));
//        cnt = 0;
        for(int i=0; i<8; i++) {
            cin>>a[i];
            vis[a[i]] = 1;
        }
        num = 0;
        dfs(0);
        cout<<"Case "<<kse<<":";
        if(num == 0)
            cout<<" No answer"<<endl;
        else if(num == 1) {
            for(int i=0; i<8; i++)
                cout<<" "<<ans[i];
            cout<<endl;
        }
        else
            cout<<" Not unique"<<endl;
        
        kse++;
    }
    return 0;
}
