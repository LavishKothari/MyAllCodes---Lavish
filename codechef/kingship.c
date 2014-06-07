#include<stdlib.h>
#include<stdio.h>

int main()
{
    int i,n;
    long long int sum;
    int t,j,*arr,min;
    long long int *answer;
    scanf("%d",&t);
    answer=(long long int*)malloc(sizeof(long long int)*t);
    for(i=0;i<t;i++)
    {
        sum=0;
        min=1000001;
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
            if(arr[j]<min)
                min=arr[j];
        }

        for(j=0;j<n;j++)
            if(arr[j]==min)
            {
            }
            else
            {
                sum+=arr[j];
            }
        answer[i]=sum*min;

    }
    for(i=0;i<t;i++)
        printf("%lld\n",answer[i]);
    return 0;
}
