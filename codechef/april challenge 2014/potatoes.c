#include<stdio.h>
#include<math.h>
int isPrime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    int t,a,i,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        for(i=1;;i++)
        {
            if(isPrime(a+b+i))
                break;
        }
        printf("%d\n",i);
    }
    return 0;
}
