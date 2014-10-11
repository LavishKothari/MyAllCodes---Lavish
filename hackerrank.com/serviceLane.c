#include<stdio.h>

int findMin(int*arr,int a,int b)
{
    int i,min=2147483647;
    for(i=a;i<=b;i++)
        if(min>arr[i])
            min=arr[i];

    return min;
}

int main()
{
    int n,t,*arr,i,a,b;
    scanf("%d%d",&n,&t);
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",findMin(arr,a,b));
    }
    return 0;
}
