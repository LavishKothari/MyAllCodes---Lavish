#include<stdio.h>

long long int findSumOfP(int n,int p)
{
    n--;
    n=n-(n%p);
    n/=p;
    n++;

    return ((long long int)n*(n-1)*p)/2;
}
long long int findsum(int n)
{
    return findSumOfP(n,3)+findSumOfP(n,5)-findSumOfP(n,15);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",findsum(n));
    }
    return 0;
}
