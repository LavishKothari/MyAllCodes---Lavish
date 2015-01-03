#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int gcdArray(int *arr,int a,int b)
{

    int g=arr[a],flag=0,i;
    for(i=a;i<=b;i++)
    {
        flag=1;
        g=gcd(g,arr[i]);
    }
    if(flag==0)
        return -1;
    return g;
}
int main()
{
    int t,*arr,n,q,i,l,r,g1,g2;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        scanf("%d",&q);
        arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&l,&r);
            l--;r--;// now indexing is from 0
            g1=gcdArray(arr,0,l-1);
            g2=gcdArray(arr,r+1,n-1);
            if(g1==-1)
                printf("%d\n",g2);
            else if(g2==-1)
                printf("%d\n",g1);
            else
                printf("%d\n",gcd(g1,g2));
        }
    }
    return 0;
}
