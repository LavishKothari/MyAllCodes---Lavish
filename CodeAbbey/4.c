#include<stdio.h>

int main()
{
    long long int t,a,b;
    //FILE *f=fopen("a.txt","w");
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld ",a<b?a:b);
        //fprintf(f,"%lld ",a<b?a:b);

    }
    return 0;
}
