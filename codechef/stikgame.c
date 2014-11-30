#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int i,*arr,a,b,c,answer,j,k,n,temp;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        qsort(arr,n,sizeof(int),cmp);
        answer=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                temp=arr[i]+arr[j];
                for(k=j+1;k<n;k++)
                {
                    if(arr[k]>temp)
                    {
                        answer+=n-k;
                        break;
                    }
                }
            }
        }
        free(arr);
        printf("%d\n",answer);
    }
    return 0;
}
