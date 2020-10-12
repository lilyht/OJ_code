#include<stdio.h>
#include<string.h>

int a[1001];

int sort(int i, int j)
{
    int t = a[i];//此时我们选择数组里的第一个数作为基准
    while(i<j)
    {
        while (i<j&&t<=a[j]) //从数组末尾开始向前遍历寻找比基准小的元素
            j--;
        if(i<j)
            a[i++] = a[j];//找到后将其填入所选的基准元素所在处（因为此时第一个数已经拿出来被当做基准，so无须担心元素丢失）
        while(i<j&&t>=a[i])//从数组前面开始向后遍历寻找比基准大的元素
            i++;
        if(i<j)
          a[j--] = a[i];//找到后将其填入上面遍历到的比基准小的元素一开始所在处
    }
    /*此时你会发现i=j，循环跳出*/
    a[i] = t;//再将基准元素填入所剩下的空缺
    
    return i;
}

void again(int i,int j)
{
    if(i>j)/*为了防止，当下标i和j被递归遍历比基准元素大的一部分时，所返回的i（赋值给s作为下一次遍历的j）*/
        return;
    int s = sort(i,j);//通过返回的基准元素最后所填入的数组下标，将数组分为俩部分
    again(i,s-1);//遍历比基准元素大的一部分
    again(s+1,j);//遍历比基准元素小的一部分
}
//打印数据（注意行末是换行）
void print(int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d%c", a[i],i==n-1?'\n':' ');
}

int main()
{
    int t, n, i;
    scanf("%d", &t);
    while (t--) 
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(i = 0; i < n; i++)
          scanf("%d", &a[i]);
        sort(0,n-1);
        again(0,n-1);
        print(n);
    }
    return 0;
}
