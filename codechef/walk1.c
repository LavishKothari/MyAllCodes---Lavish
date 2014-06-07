#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,t,*arr,n,j,k,min,flag,temp,max,maxIndex;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        max=0;
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
            if(max<arr[j])
            {
                max=arr[j];
                maxIndex=j;
            }
        }
        for(j=max+maxIndex;;j++)
        {
            flag=0;
            temp=j;
            for(k=0;k<n;k++)
            {
                if(temp<arr[k])
                {
                    j=j+arr[k]-temp-1;
                    flag=1;
                    break;
                }
                temp--;
            }
            if(flag==0)
            {
                break;
            }
        }
        printf("%d\n",j);
    }
    return 0;
}
