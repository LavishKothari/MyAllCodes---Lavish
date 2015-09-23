#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int n,i,*arr,*diff,f;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    diff=(int*)malloc(sizeof(int)*(n-1));
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    qsort(arr,n,sizeof(int),cmp);
    for(i=1;i<n;i++)
        diff[i-1]=arr[i-1]-arr[i];
    f=diff[0];
    for(i=1;i<n-1;i++)
        f=gcd(f,diff[i]);
    //printf("this is a test %d\n",f);
    for(i=2;i<=f;i++)
        if(f%i==0)
            printf("%d ",i);
}
