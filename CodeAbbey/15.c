#include<stdio.h>
int main()
{
    int arr[300],min,max,i;
    for(i=0;i<300;i++)
    {
        scanf("%d",&arr[i]);
        if(i==0)
            min=max=arr[i];
        if(min>arr[i])
            min=arr[i];
        if(max<arr[i])
            max=arr[i];
    }
    printf("%d %d",max,min);
    return 0;
}
