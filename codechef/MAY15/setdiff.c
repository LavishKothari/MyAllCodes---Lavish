#include<stdlib.h>
#include<stdio.h>
#define MOD 1000000007
long long int power(long long int p,long long int q)
{
    long long int t;
    if(q==0)
        return 1;
    if(q==1)
        return p;
    t=power(p,q/2);
    if(q%2==0)
        return (t*t)%MOD;
    return (((t*t)%MOD)*p)%MOD;
}
int cf(const void *a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    long long int t,i,n,*arr,a,b;
    long long int answer;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        arr=(long long int*)malloc(sizeof(long long int)*n);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        qsort(arr,n,sizeof(long long int),cf);
        answer=0;
        for(i=0;i<n;i++)
        {
            a=(arr[i]*(power(2,i)-1))%MOD;
            b=(arr[i]*((long long int)power(2,n-i-1)-1))%MOD;
            answer=(answer + a - b)%MOD;
        }
        if(answer<0)
            answer+=MOD;
        printf("%lld\n",answer);
        free(arr);
    }
    return 0;
}
