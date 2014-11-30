#include<stdio.h>
#include<math.h>
int isPerfectSquare(long long int n)
{
    int s=(int)sqrt(n);
    if(s*s==n)
        return 1;
    return 0;
}
int isFibo(int n)
{
    return isPerfectSquare((long long int)5*n*(long long int)n+4) || isPerfectSquare((long long int)5*n*(long long int)n-4);
}
int main()
{
    int t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(isFibo(n))
            printf("is fibo\n");
        else
            printf("not fibo\n");
    }
    return 0;
}
