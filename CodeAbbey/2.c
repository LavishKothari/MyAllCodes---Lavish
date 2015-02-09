#include<stdio.h>

int main()
{
    long long int n,i,temp,sum=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&temp);
        sum+=temp;
    }
    printf("%lld",sum);
    return 0;
}
