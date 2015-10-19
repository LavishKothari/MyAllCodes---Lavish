#include<stdio.h>

int main()
{
    int *arr,n,i,j;
    long long int sum;
    scanf("%d",&n);

    arr=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sum=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            sum+=(arr[i]&arr[j]);
        }

    }
    printf("%lld",sum);
    return 0;
}
