#include<stdio.h>
#include<stdlib.h>
int cmpfunction(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

int main()
{
    int t,n,*arr,i;
    long long int sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        qsort(arr,n,sizeof(int),cmpfunction);
        for(i=n-1;i>=0;i-=2)
            sum+=arr[i];
        printf("%lld\n",sum);
    }
    return 0;
}
