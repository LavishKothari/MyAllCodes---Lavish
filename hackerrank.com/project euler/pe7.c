#include<stdio.h>
long long int primes[10001];
int index=0;
int isPrime(long long int n)
{
    long long int i;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}
void initializePrimeArray()
{
    long long int i;
    int counter=1;
    for(i=2;counter!=10001;i++)
    {
        if(isPrime(i))
            primes[counter++]=i;
    }
}

int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    initializePrimeArray();
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",primes[n]);
    }
    return 0;
}
