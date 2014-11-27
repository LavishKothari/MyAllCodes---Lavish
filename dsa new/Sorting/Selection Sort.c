#include<stdio.h>
void selectionSort(int arr[],int n)
{
    int minIndex,i,j,temp;
    for(i=0;i<n-1;i++)
    {
        minIndex=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[minIndex])
                minIndex=j;
        temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

void selectionSortIndexed(int arr[],int a,int b)
{
    int i,j,temp,minIndex;
    for(i=a;i<b;i++)
    {
        minIndex=i;
        for(j=i+1;j<=b;j++)
            if(arr[j]<arr[minIndex])
                minIndex=j;
        temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}
int main()
{
    int arr[]={3,8,1,23,7,9,24,6,12};
    int n=9,i;
    selectionSortIndexed(arr,3,6);
    for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
}

