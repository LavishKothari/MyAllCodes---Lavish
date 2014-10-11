#include<stdio.h>
#define MAX 10000000
int isPermutation(int a,int b)
{
    int flaga[10],flagb[10],i;
    for(i=0;i<10;i++)
        flaga[i]=flagb[i]=0;
    while(a)
    {
        flaga[a%10]++;
        a/=10;
    }
    while(b)
    {
        flagb[b%10]++;
        b/=10;
    }
    for(i=0;i<10;i++)
        if(flaga[i]!=flagb[i])
            return 0;
    return 1;
}
int phi(int n)
{
    /*
        this is the implementation of Euler's Totient function.
    */
    int cn,pro=1,i;
    cn=n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            pro=pro*(i-1);
            cn/=i;
        }
        while(n%i==0)
            n/=i;
    }
    pro*=cn;
    return pro;
}
int main()
{
    int i,n;
    double p,min=2147483647.0,ph,epsilon=0.000000001;
    for(i=2;i<MAX;i++)
    {
        if(i%100000==0)
            printf("%d\n",i);
        ph=(double)phi(i);
        if(isPermutation(i,ph))
        {
            p=n/ph;
            if(min-p > epsilon)
            {
                min=p;
                n=i;
            }
        }
    }
    printf("answer = %d\n",n);
    return 0;
}
