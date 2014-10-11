#include<stdio.h>
#include<stdlib.h>
int min2(int a,int b)
{
    return a<b?a:b;
}
int min3(int a,int b,int c)
{
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else if(c<a && c<b)
        return c;
    else if(a<b)
        return a;
    else if(a<c)
        return a;
    else if(c<b)
        return c;
    else
        return a;
}
void constructMinArray(int **narr,int**arr,int m,int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(i==0)
                narr[i][j]=arr[i][j];
            else if(j==m-1)
                narr[i][j]=arr[i][j]+min2(narr[i-1][j-1],narr[i-1][j]);
            else if(j==0)
                narr[i][j]=arr[i][j]+min2(narr[i-1][j],narr[i-1][j+1]);
            else
                narr[i][j]=arr[i][j]+min3(narr[i-1][j-1],narr[i-1][j],narr[i-1][j+1]);
        }

}
int findMinimum(int*arr,int len)
{
    int i,min=2147483647;
    for(i=0;i<len;i++)
        if(min>arr[i])
            min=arr[i];
    return min;
}
int main()
{
    int t,max,**arr,**minArray,min,m,i,j,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&max);
        scanf("%d%d",&n,&m);
        arr=(int**)malloc(sizeof(int*)*n);
        minArray=(int**)malloc(sizeof(int*)*n);
        for(i=0;i<n;i++)
        {
            arr[i]=(int*)malloc(sizeof(int)*m);
            minArray[i]=(int*)malloc(sizeof(int)*m);
        }

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&arr[i][j]);
        constructMinArray(minArray,arr,m,n);
        min=findMinimum(minArray[m-1],n);
        if(min<max)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
