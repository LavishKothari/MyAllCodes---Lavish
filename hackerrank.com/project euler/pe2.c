#include<stdio.h>

long long int findsum(long long int n)
{
    long long int sum=0,a,b,c;
    a=1;b=2;
    while(1)
    {
        c=a+b;

        if(c>n)
            break;
        if(c%2==0)
            sum+=c;
        a=b;
        b=c;
    }
    sum+=2;
    return sum;
}

int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",findsum(n));
    }
    return 0;
}
