#include<stdio.h>
#define MOD 1000000007

long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long long int power(long long int a,long long int b)
{
    long long int t;
    if(b==0)
        return 1;
    if(b==1)
        return a;
        
    t=power(a,b/2);
    if(b%2==0) 
        return (t*t)%MOD;
    else
        return (((t*t)%MOD)*a)%MOD;
}
long long int phi(long long int n)
{
    int flag;
    long long int d,p,cn,i,pi;
    cn=n;p=n;d=1;
    for(i=2;cn!=1 && i<primeLimit;i++)
    {
        flag=0;
        pi=i;
        while(cn%pi==0)
        {
            flag=1;
            cn/=pi;
        }
        if(flag==1)
        {
            p=p*(pi-1);
            d=d*pi;
        }
    }
    return p/d;
}
int main()
{
    long long int t,n,i,p,k,sum=0;
    
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        scanf("%lld%lld",&n,&k);
        if(k!=0)
        {
            for(i=1;i<=n;i++)
            {
                if(gcd(n,i)==1)
                {
                    sum=(sum+power(i,k))%MOD;
                }
            }
            printf("%lld\n",sum);
        }
        else
            printf("%lld\n",phi(n));
    }
}
