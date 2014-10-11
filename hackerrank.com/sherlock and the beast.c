#include<stdio.h>
int main()
{
    int t,cn,i,p,d,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cn=n;
        if(n%3==0)
        {
            for(i=0;i<n;i++)
                printf("5");
            printf("\n");
            continue;
        }
        else
        {
            while(cn%3!=0)
                cn-=5;
            if(cn<0)
            {
                printf("-1\n");
                continue;
            }
            p=5;
            for(i=0;i<n;i++)
            {
                if(i==cn)
                    p=3;
                printf("%d",p);
            }
        }
        printf("\n");
    }
    return 0;
}
