#include<stdio.h>

int main()
{
    int n,m,i,temp,flag=0,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&temp);
            if(temp==m)
                flag=1;
        }
    if(flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}
