#include<stdio.h>

double explicitRadius(double a,double b,double c,double d)
{
    return sqrt((a-c)*(a-c)+(d-b)*(d-b));
}

int isInteger(double n)
{
    if(n==(int)n)
        return 1;
    return 0;
}

double calRadius(double a,double b,double c,double d,double e,double f)
{
    double x,y;
    x = (a*a * (-d)+a*a*f-b*b *d+b*b*f+b *c*c+b *d*d-b *e*e-b *f*f-c*c *f-d*d *f+d*e*e+d*f*f)/(2* (-a *d+a *f+b *c-b *e-c* f+d* e));
    y = -(a*a *c-a*a* e-a *c*c-a* d*d+a *e*e+a *f*f+b*b *c-b*b* e+c*c *e-c *e*e-c* f*f+d*d *e)/(2* (a *d-a* f-b *c+b* e+c *f-d *e));
    if(isInteger(explicitRadius(a,b,x,y)))
        return explicitRadius(a,b,x,y);
    else return 0;
}

int main()
{
    int n,i,*x,*y,t,j,k;
    double radius,max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        x=(int*)malloc(sizeof(int)*n);
        y=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            scanf("%d",&y[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    radius=calRadius(x[i],y[i],x[j],y[j],x[k],y[k]);
                    if(radius>max)
                        max=radius;
                }
            }
        }
        printf("%d\n",(int)radius);
    }
    return 0;
}
