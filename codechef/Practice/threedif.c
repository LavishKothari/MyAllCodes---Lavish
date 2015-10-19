#include<stdio.h>

int main()
{
    int t;
    long long int a,b,c,max,min,mid,answer;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%lld%lld%lld",&a,&b,&c);

        if(a>=b && a>=c)
            max=a;
        else if(b>=a && b>=c)
            max=b;
        else if(c>=b && c>=a)
            max=c;

        if(a<=b && a<=c)
            min=a;
        if(b<=a && b<=c)
            min=b;
        if(c<=b && c<=a)
            min=c;

        if(max==a && min==b)
            mid=c;
        if(max==a && min==c)
            mid=b;
        if(max==b && min==a)
            mid=c;
        if(max==b && min==c)
            mid=a;
        if(max==c && min==a)
            mid=b;
        if(max==c && min==b)
            mid=a;

        answer=((((min%1000000007)*((mid-1)%1000000007))%1000000007)*((max-2)%1000000007))%1000000007;
        printf("%lld\n",answer);
    }
    return 0;
}
