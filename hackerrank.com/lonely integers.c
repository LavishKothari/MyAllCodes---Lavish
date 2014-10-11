#include<stdio.h>

int main()
{
    int n,i,*arr,flag[101];
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);

    for(i=0;i<=100;i++)
        flag[i]=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        flag[arr[i]]++;
    }
    for(i=0;i<=100;i++)
        if(flag[i]%2)
        {
            printf("%d\n",i);
            break;
        }
    return 0;
}
