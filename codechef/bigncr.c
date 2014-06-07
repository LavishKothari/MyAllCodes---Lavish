#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
    return (a>b?b:a);
}
long long power(int a, int b, int MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return power(n,MOD-2,MOD);
}

long long C(int n, int r, int MOD)
{
    int i;
    //vector<long long> f(n + 1,1);
    int*f;
    f=(int*)malloc(sizeof(int)*1000001);
    for(i=0;i<1000001;i++)
        f[i]=1;
    for (i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int permute(int a,int b)
{
    return C(a+b,(min(a,b)),1000000007);
}
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
            if(n-2*counter == -2 || n-2*counter == -1)
                break;
            printf("per = %d\n",permute(counter,n-2*counter));
            answer=(answer+permute(counter,n-2*counter))%1000000007;
            counter++;
        }
        printf("%d\n",answer);
    }
    return 0;
}
