#include<stdio.h>

int main()
{
    int t,n,i,zero,temp,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=0;
        zero=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp==0)
                zero++;
            sum+=temp;
        }
        if(sum>=100 && sum<100+n-zero)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
