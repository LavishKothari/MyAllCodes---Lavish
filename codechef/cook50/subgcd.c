#include<stdio.h>

int gcd(int a,int b)
{
    int temp;
    if(b>a)
    {
        temp=a;
        a=b;
        b=temp;
    }
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int n,t,*arr,i,answer,max,j,h;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        arr=(int *)malloc(sizeof(int)*n);

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        h=arr[0];
        for(i=0;i<n;i++)
        {
            h=gcd(h,arr[i]);
            if(h==1)
                break;
        }
        if(h==1)
            printf("%d\n",n);
        else
            printf("-1\n");


    }
    return 0;
}
