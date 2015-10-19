#include<stdio.h>

int isPresent(long long int a,long long int b)
{
    long long int ca,cb;
    ca=a;
    cb=b;

    while(a)
    {
        while(a && b)
        {
            if(a%10 == b%10)
            {
                a/=10;
                b/=10;
            }
            else
                break;
        }
        if(!b)
            return 1;
        ca/=10;
        a=ca;
        b=cb;
    }
    return 0;
}

int main()
{
    long long int num,n;
    printf("Enter two numbers : \n");
    scanf("%lld%lld",&num,&n);

    if(isPresent(num,n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
