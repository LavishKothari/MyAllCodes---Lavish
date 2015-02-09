#include<stdio.h>

void insertionSort(int arr[],int n)
{
    int key,i,j,temp;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        for(j=i-1;j>=0 && key<arr[j];j--)
            arr[j+1]=arr[j];
        arr[j+1]=key;
    }
}
void insertionSortIndexed(int arr[],int a,int b) // sorting subArray from arr[a] to arr[b]
{
    int key,i,j,temp,n;
    n=b-a+1;
    for(i=a+1;i<=b;i++)
    {
        key=arr[i];
        for(j=i-1;j>=a && key<arr[j];j--)
            arr[j+1]=arr[j];
        arr[j+1]=key;
    }
}
int main()
{
    int arr[]={3,8,1,23,7,9,24,6,12};
    int n=9,i;
    insertionSortIndexed(arr,3,6);
    for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
}
