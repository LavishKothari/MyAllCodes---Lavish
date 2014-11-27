#include<stdio.h>

int main()
{
    int t;
    int n,k;
    long long int answer;
    scanf("%d",&t);
    while(t--)
    {
        answer=1;
        scanf("%d%d",&n,&k);
        answer=((long long int)n*(n-1)*(n-2)/6 - (long long int)k*(k-1)*(k-2)/6);
        printf("%lld\n",answer);
    }
    return 0;
}
