#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
#define primeLimit 10000
long long int sum=0;
long long int *primes;
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
int isPrime(long long int n)
{
    long long int i;
    for(i=2;i*i<=n;i++)
        if(n%i==0)  
            break;
}
long long int phi(long long int n)
{
    int flag;
    long long int d,p,cn,i,pi;
    cn=n;p=n;d=1;
    for(i=2;cn!=1 && i<primeLimit;i++)
    {
        flag=0;
        pi=primes[i];
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
        else
            sum=(sum+pi)%MOD;
    }
    return p/d;
}
void fillPrimes(long long int primes[],long long int n)
{
    long long int i,counter=0;
    for(i=2;;i++)
    {
        if(isPrime(i))
            primes[counter++]=i;
        if(counter==n)
            break;
    }
}
long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    long long int t,n,i,p,k;
    /*
    primes=(long long int *)malloc(sizeof(long long int )*primeLimit);
    fillPrimes(primes,primeLimit);
    printf("done\n");
    */
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        scanf("%lld%lld",&n,&k);
        //p=phi(n); 
        for(i=1;i<n;i++)
        {
            if(gcd(n,i)==1)
                sum=(sum+power(i,k))%MOD;
        }
        printf("%lld\n",sum);
        /*if(k==0)
        {
            printf("%lld\n",phi(n));
            continue;
        }
        if(k==1)
        {
            phi(n);
            printf("%lld\n",sum);
            continue;
        }
        */
//        printf("0\n");
    }
}
