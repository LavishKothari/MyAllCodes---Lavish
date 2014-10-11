#include<stdio.h>
#include<math.h>

int isPointInsideCircle(long long int xc,long long int yc,long long int radius,long long int a,long long int b)
{
    if((a-xc)*(a-xc)+(b-yc)*(b-yc) < radius*radius)
        return 1;
    return 0;
}

int isIntersecting(long long int xc,long long int yc,long long int radius,long long int a,long long int b,long long int c,long long int d)
{
    long long int x1,y1,constant;
    x1=b-d;
    y1=c-a;
    constant=d*(a-c)+c*(d-b);

    if(isPointInsideCircle(xc,yc,radius,a,b) && isPointInsideCircle(xc,yc,radius,c,d))
        return 0;

    if((x1*xc+y1*yc+constant)*(x1*xc+y1*yc+constant) <= radius*radius*(x1*x1+y1*y1))
        return 1;
    return 0;
}

int main()
{
    int t;
    long long int xc,yc,radius,a,b,c,d,e,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&xc,&yc,&radius);
        scanf("%lld%lld",&a,&b);
        scanf("%lld%lld",&c,&d);
        scanf("%lld%lld",&e,&f);

        if(isIntersecting(xc,yc,radius,a,b,c,d) || isIntersecting(xc,yc,radius,c,d,e,f) || isIntersecting(xc,yc,radius,e,f,a,b))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
