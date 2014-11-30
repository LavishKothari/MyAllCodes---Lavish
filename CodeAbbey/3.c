#include<stdio.h>

int main()
{
    long long int n,i,a,b,sum=0;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld",&a,&b);
        sum=a+b;
        printf("%lld ",sum);
    }
    return 0;
}
