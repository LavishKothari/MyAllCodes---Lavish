#include<stdio.h>

int main()
{
    long long int i,t,n,m,answer;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&m,&n);
        answer=((long long int)1<<n);
        for(i=m;i<=n;i++)
            answer=answer-((long long int)1<<(n-i));
        printf("%lld\n",answer);
    }
    return 0;
}
