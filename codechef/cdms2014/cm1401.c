#include<stdio.h>

int main()
{
    int t,n,a,i,preva,p;
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        scanf("%d",&n);
        scanf("%d",&preva);
        for(i=1;i<n;i++)
        {
            scanf("%d",&a);
            if(preva==a)
                p++;
            else
                p+=2;
        }
        printf("%d\n",p);
    }
    return 0;
}
