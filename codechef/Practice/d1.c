#include<math.h>
#include<stdio.h>
int main()
{
    int t,n,i,s;
    long long int pro;
    scanf("%d",&t);
    while(t--)
    {
        pro=1;
        scanf("%d",&n);
        s=(int)sqrt(n);
        for(i=2;i<=s;i++)
        {
            if(n%i==0 && i*i!=n)
                pro=(pro*n)%10000;
            else if(i*i==n)
                pro=(pro*i)%10000;
        }
        printf("%lld\n",pro);
    }
    return 0;
}
