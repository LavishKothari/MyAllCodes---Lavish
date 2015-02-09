#include<stdlib.h>
#include<stdio.h>
int main()
{
    int n,*arr,*to,i,j,q,a,b;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    to=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n && arr[j]<=arr[i];j++);
        to[i]=j;
    }
    /*
    for(i=0;i<n;i++)
        printf("%d ",to[i]);
    */
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        a--;b--;
        if(to[a]>=b)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
