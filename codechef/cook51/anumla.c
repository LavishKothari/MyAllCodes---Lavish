#include<stdio.h>

long long int findAnswer(long long int n)
{
    return (n*n+3*n)/2;
    //return (n*(n+1))/2 + n;
}

int main()
{
    int t,n;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        printf("%lld\n",findAnswer(n));
    }
    return 0;
}
