#include<stdio.h>
int main()
{
    long long int i,product=1,n;
    //scanf("%lld",&n);
    n=10000000;
    product=1;
    for(i=1;i<=n;++i)
    {
        product*=i;
        while(product%10==0)
            product/=10;
        product%=10000000;
        if(i==n)
            printf("factorial(%lld) = %lld\n",i,product);
    }


    return 0;
}
