#include<stdio.h>
#include<conio.h>

int main()
{
    int max,t,i,a,b,min;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d%d",&a,&b);
        min=(a>b?a:b);
        max=a+b;

        printf("%d %d\n",min,max);
    }
}
