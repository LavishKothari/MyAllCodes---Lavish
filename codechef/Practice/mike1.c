#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,i,j,**arr,l,a,b,flag1,flag2,flag11=0,flag22=0;
    long long int sum1=0,sum2=0,answer;
    scanf("%d%d",&m,&n);
    arr=(int**)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++)
    {
        arr[i]=(int*)malloc(sizeof(int)*n);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    scanf("%d",&l);
    for(i=0;i<l;i++)
    {
        flag1=flag2=0;
        scanf("%d%d",&a,&b);
        if(a>m || b>n)
        {
            flag11=1;
            sum1+=-1;
            flag1=1;
        }
        if(a>n || b>m)
        {
            flag22=1;
            sum2+=-1;
            flag2=1;
        }
        if(flag1==0)
            sum1+=arr[a-1][b-1];
        if(flag2==0)
            sum2+=arr[b-1][a-1];
    }
    if(flag11==1)
        sum1=-1;
    if(flag22==1)
        sum2=-1;
    answer=(sum1>sum2)?sum1:sum2;
    printf("%lld",answer);
    return 0;
}
