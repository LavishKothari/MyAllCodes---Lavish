#include<stdio.h>

int main()
{
    int t,a,b,n;
    long long int answer;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a=n/2;
        b=n-a;
        answer=(long long int)a*b;
        printf("%lld\n",answer);
    }
    return 0;
}
