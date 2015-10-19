#include<stdio.h>
#include<stdlib.h>

long long int fun(long long int *a,long long int *b,int k,int n)
{
    n=k*k-n+1;
    //printf("hello %d\n%lld\n",n,a[n/k]+b[n/(n/k)]);
    if(n%k==0)
        return a[n/k-1]+b[(n-1)%k];
    else
        return a[n/k]+b[n%k-1];
}

int cmpfunc (const void * a, const void * b)
{
    if( *(long long int*)a - *(long long int*)b < 0 )
        return -1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return 1;
    if( *(long long int*)a - *(long long int*)b == 0 )
        return 0;
}

int main()
{
    long long int *a,*b;
    int k;
    int t,q,temp,i;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&k,&q);

        a=(long long int*)malloc(sizeof(long long int)*k);
        b=(long long int*)malloc(sizeof(long long int)*k);

        for(i=0;i<k;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<k;i++)
            scanf("%lld",&b[i]);

        qsort(a,k,sizeof(long long int),cmpfunc);
        qsort(b,k,sizeof(long long int),cmpfunc);

        for(i=0;i<q;i++)
        {
            scanf("%d",&temp);
            printf("%lld\n",fun(a,b,k,temp));
        }
    }
    return 0;
}
