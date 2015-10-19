#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,i,*arr,max,j,k,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        max=0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                for(k=j+1;k<n;k++)
                    if((arr[i]^arr[j]^arr[k])>max)
                        max=(arr[i]^arr[j]^arr[k]);
        free(arr);
        printf("%d\n",max);
    }
    return 0;
}
