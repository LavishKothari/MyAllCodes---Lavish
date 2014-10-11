#include<stdio.h>

int main()
{
    long long int answer,m,n,t,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        answer=0;
        for(i=1;i<=n;i++)
            answer=(answer+((((((((((i)%m)*i)%m)*i)%m)*i)%m)*((int)(n/i)))%m))%m;
        printf("%lld\n",answer);
    }
    return 0;
}
