#include<stdio.h>

long long int findLargestPrimeFactor(long long int n)
{
    int i;
    long long int counter=3,answer;
    while(n%2==0)
        n/=2;

    for(i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            answer=i;
            n/=i;
        }
    }
    if(n>2)
        return n;
    else
        return answer;
}

int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",findLargestPrimeFactor(n));
    }
    return 0;
}
