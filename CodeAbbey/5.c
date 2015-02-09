#include<stdio.h>

int main()
{
    long long int t,a,b,c;
    FILE *f=fopen("a.txt","w");
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld ",a<b?(a<c?a:c):(b<c?b:c));
        fprintf(f,"%lld ",a<b?(a<c?a:c):(b<c?b:c));

    }
    return 0;
}
