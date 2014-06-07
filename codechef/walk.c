#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,t,*arr,n,j,finalanswer,max,maxIndex,answer,*checkarr,k,min,flag;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        max=0;
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*n);
        checkarr=(int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
            checkarr[j]=j+arr[j];
        }
        min=1000001;
        for(k=0;k<n;k++)
        {
            flag=0;
            answer=checkarr[k];
            if(answer<min)
            {
                for(j=0;j<n;j++)
                {
                    if(answer<arr[j])
                    {
                        flag=1;
                        break;
                    }
                    answer--;
                }
                if(flag==0)
                {
                     if(min>checkarr[k])
                        min=checkarr[k];
                }
            }
        }

        printf("%d\n",min);
    }
    return 0;
}
