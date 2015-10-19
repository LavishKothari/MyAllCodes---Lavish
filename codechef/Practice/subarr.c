#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr,n,k,i,j,answer;
    long long int*sum;
    scanf("%d%d",&n,&k);
    sum=(long long int*)calloc(n,sizeof(long long int));
    arr=(int*)calloc(n,sizeof(int));
    answer=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(i==0)
            sum[i]=arr[i];
        else
            sum[i]=sum[i-1]+arr[i];

        for(j=i;j<n;j++)
        {
            if(i!=0)
            {
                 if((sum[j]-sum[i-1])/((float)(j-i+1)) >= k)
                     answer++;

            }
            else
            {
                if(sum[j]/((float)(j+1))>=k)
                    answer++;

            }
        }
    }

    printf("%d",answer);
    return 0;
}
