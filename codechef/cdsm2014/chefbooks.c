#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,*arr,n,m,i,answer,totalSum,j,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        arr=(int*)malloc(sizeof(int)*n);
        totalSum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            totalSum+=arr[i];
        }
        for(i=0;i<n;i++)
            for(j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    tmp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=tmp;
                }
            }
        answer=0;
        for(i=0;i<m;i++)
            answer+=arr[i];
        answer=totalSum-2*answer;
        printf("%d\n",answer);
    }
    return 0;

}
