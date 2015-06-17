#include<stdio.h>

long long int gcd_Euclid_Recursive(long long int a,long long int b)
{
    if(b==0)
        return a;
    return gcd_Euclid_Recursive(b,a%b);
}


long long int gcd_Euclid_NonRecursive(long long int a,long long int b)
{
    long long int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    long long int a,b;
    printf("Enter two number : ");
    scanf("%lld%lld",&a,&b);
    printf("gcd(%lld,%lld) = %lld\n",a,b,gcd_Euclid_Recursive(a,b));
    printf("gcd(%lld,%lld) = %lld\n",a,b,gcd_Euclid_NonRecursive(a,b));
    return 0;
}
