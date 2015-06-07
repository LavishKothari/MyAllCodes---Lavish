#include<stdio.h>
long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{  
    long long int a,h,b,h1,temp;
    int t,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a%b==0)
        {
            printf("Yes\n");
            continue;
        }
        h=gcd(a,b);
        if(h==1)
            printf("No\n");
        else
        {
            temp=b/h;
            do
            {
                h1=gcd(temp,h);
                temp/=h1;        
            }
            while(temp!=1 && h1!=1);
            if(h1==1)
                printf("No\n");
            else if(temp==1)
                printf("Yes\n");
        }
    }
    return  0;
}
