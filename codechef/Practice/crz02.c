#include<stdio.h>

#define MOD 1000000007

int p(int,int);
int main()
{
    int t,n,answer,counter;
    scanf("%d",&t);
    while(t--)
    {
        answer=1;
        counter=1;
        scanf("%d",&n);
        while(1)
        {
            if(n-2*counter == 0)
                break;
            answer=(answer+p(counter,n-2*counter))%MOD;
            counter++;
        }
        printf("%d\n",answer);
    }
    return 0;
}

int p(int a,int b)
{
    return C(a+b,(min(a,b)));
}

int C(int n,int r)
{
    if(n==1)
        return 1;
    return (C(n-1,r)*(n+1)*modInverse(n-r));
}
int modPow(int a, int x, int p)
{
    //calculates a^x mod p
    int res = 1;
    while(x > 0)
    {
        if( x % 2 != 0)
        {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return (res%MOD);
}
int modInverse(int a, int p)
{
    //calculates the modular multiplicative of a mod m assuming p is prime
    return modPow(a, p-2, p);
}

int min(int a,int b)
{
    return (a>b?b:a);
}
