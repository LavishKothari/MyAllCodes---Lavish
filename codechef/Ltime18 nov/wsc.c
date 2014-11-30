#include<stdio.h>
#include<stdlib.h>
int isPossible(int x[],int y[],int f[],int n,int m)
{
    int i,j,flag;
    for(i=1;i<=n;i++)
    {
        flag=0;
        if(f[i])
        {
            for(j=0;j<m;j++)
            {
                if(i==x[j] || i==y[j])
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1 && n==3)
        {
            return 1;
        }
    }

    return 0;
}
int main()
{
    int t,*x,*y,n,m,i,*f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(m==0)
        {
            printf("YES\n");
            continue;
        }
        x=(int*)malloc(sizeof(int)*(m));
        y=(int*)malloc(sizeof(int)*(m));
        f=(int*)malloc(sizeof(int)*(n+1));
        for(i=0;i<=n;i++)
            f[i]=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            f[x[i]]++;
            f[y[i]]++;
        }
        if(n<=3 || m==1)
        {
            printf("YES\n");
            free(x);
            free(y);
            free(f);
            continue;
        }
        if(isPossible(x,y,f,n,m))
            printf("YES\n");
        else
            printf("NO\n");
        free(x);
        free(y);
        free(f);
    }
    return 0;
}
