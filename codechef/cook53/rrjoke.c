#include<stdio.h>

int main()
{
    int t,a,b,answer,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        answer=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            answer=answer^i;
        }
        printf("%d\n",answer);
    }
    return 0;
}
