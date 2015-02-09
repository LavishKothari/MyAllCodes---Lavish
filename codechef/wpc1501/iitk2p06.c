#include<stdio.h>
#include<math.h>
int main()
{
    int t,ans,e,o;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&e,&o);
        if(((e+o))%5==0)
        {
            ans=abs((3*e-2*o))/5;
            printf("%d\n",ans);
        }
        else
            printf("-1\n");
    }
    return 0;
}
