#include<stdio.h>
#include<stdlib.h>
long long int max(long long int arr[],int len)
{
    int i;
    long long int m=arr[0];
    for(i=1;i<len;++i)
        if(m<arr[i])
            m=arr[i];
    return m;
}
int main()
{
    int n,k,i,j;
    long long int *arr,m;
    scanf("%d%d",&n,&k);
    arr=(long long int*)malloc(sizeof(long long int)*n);
    for(i=0;i<n;scanf("%lld",&arr[i]),++i);

    if(k==0);
    else if((k&1)==0)
        k=2;
    else
        k=1;
    while(k--)
    {
        m=max(arr,n);
        for(j=0;j<n;arr[j]=m-arr[j],++j);
    }
    for(i=0;i<n;printf("%lld ",arr[i]),++i);
    free(arr);
    return 0;
}
