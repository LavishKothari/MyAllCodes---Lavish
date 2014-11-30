#include<stdio.h>
int hcf(int a,int b)
{
    if(b==0)
        return a;
    return hcf(b,a%b);
}
int main()
{
    int t,n,i,*a,h;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i==0)
            {
                h=a[i];
                continue;
            }
            h=hcf(h,a[i]);
        }
        for(i=0;i<n;i++)
            printf("%d ",a[i]/h);
        free(a);
        printf("\n");
    }
    return 0;
}
