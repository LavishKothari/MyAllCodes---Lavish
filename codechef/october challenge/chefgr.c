#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,n,m,i,max,*arr,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);

        arr=(int*)malloc(sizeof(int)*n);
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(max<arr[i])
                max=arr[i];
        }
        sum=0;
        for(i=0;i<n;i++)
            sum+=max-arr[i];

        if(sum==m || (m-sum)%n==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
