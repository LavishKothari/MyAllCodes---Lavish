#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int i,n,k,*arr,min,j;
    scanf("%d%d",&n,&k);
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    qsort(arr,n,sizeof(int),cmpfunc);

    min=2147483647;
    for(i=0,j=i+k-1;j<n;j++,i++)
        if(arr[j]-arr[i]<min)
            min=arr[j]-arr[i];

    printf("%d\n",min);
}
