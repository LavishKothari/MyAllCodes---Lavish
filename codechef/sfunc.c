#include<stdio.h>
#include<math.h>
long long int hcf(long long int,long long int);
int main()
{
    long long int i,n,k,m,answer=0;


    scanf("%lld%lld%lld",&n,&k,&m);
    for(i=1;i<n;i++)
    {
        if(hcf(i,n)==1)
        {
            answer=(answer+((long long int)pow(i,k)%m))%m;
        }
    }
    answer=answer%m;
    printf("%lld",answer);

    //printf("%d",hcf(12,4));
    return 0;
}

long long int hcf(long long int a,long long int b)
{
    long long int h,min=a,r,max=b;
    min=(a<b)?a:b;
    max=(a>b)?a:b;

    h=min;
    r=max%min;

    while(r)
    {
        max=min;
        min=r;
        r=max%min;
    }
    return min;
}
