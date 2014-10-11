#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findMin(int *arr,int n)
{
    int i;
    int min=2147483647;
    for(i=0;i<n;i++)
    {
        if(min>arr[i] && arr[i]>0)
            min=arr[i];
    }
    return min;
}
int countRods(int *arr,int n)
{
    int i,answer=0;
    for(i=0;i<n;i++)
        if(arr[i]>0)
            answer++;
    return answer;
}
int main()
{
    int n,min,i,counter;
    int *arr;

    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    while(1)
    {
        printf("%d\n",countRods(arr,n));
        min=findMin(arr,n);
        //printf("min = %d\n",min);
        counter=0;
        for(i=0;i<n;i++)
        {
            arr[i]-=min;
            if(arr[i]<=0)
                counter++;
        }
        if(counter==n)
            break;
    }
    return 0;
}
