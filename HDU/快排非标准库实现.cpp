#include<stdio.h>
#include<string.h>

int a[1001];

int sort(int i, int j)
{
    int t = a[i];//��ʱ����ѡ��������ĵ�һ������Ϊ��׼
    while(i<j)
    {
        while (i<j&&t<=a[j]) //������ĩβ��ʼ��ǰ����Ѱ�ұȻ�׼С��Ԫ��
            j--;
        if(i<j)
            a[i++] = a[j];//�ҵ�����������ѡ�Ļ�׼Ԫ�����ڴ�����Ϊ��ʱ��һ�����Ѿ��ó�����������׼��so���뵣��Ԫ�ض�ʧ��
        while(i<j&&t>=a[i])//������ǰ�濪ʼ������Ѱ�ұȻ�׼���Ԫ��
            i++;
        if(i<j)
          a[j--] = a[i];//�ҵ�������������������ıȻ�׼С��Ԫ��һ��ʼ���ڴ�
    }
    /*��ʱ��ᷢ��i=j��ѭ������*/
    a[i] = t;//�ٽ���׼Ԫ��������ʣ�µĿ�ȱ
    
    return i;
}

void again(int i,int j)
{
    if(i>j)/*Ϊ�˷�ֹ�����±�i��j���ݹ�����Ȼ�׼Ԫ�ش��һ����ʱ�������ص�i����ֵ��s��Ϊ��һ�α�����j��*/
        return;
    int s = sort(i,j);//ͨ�����صĻ�׼Ԫ�����������������±꣬�������Ϊ������
    again(i,s-1);//�����Ȼ�׼Ԫ�ش��һ����
    again(s+1,j);//�����Ȼ�׼Ԫ��С��һ����
}
//��ӡ���ݣ�ע����ĩ�ǻ��У�
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
