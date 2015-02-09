#include<stdio.h>
int f[1000001];
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int t,i,a,b;
    scanf("%d",&t);
    f[0]=0;
    f[1]=1;

    for(i=2;i<1000001;i++)
        f[i]=(f[i-1]+f[i-2])%1000000007;
    while(t--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",f[gcd(a,b)]);
    }
    return 0;
}
