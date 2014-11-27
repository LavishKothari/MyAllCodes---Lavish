#include<stdio.h>

void bubbleSort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void bubbleSortImproved(int arr[],int n)
{
    int i,j,temp,flag=0;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==0)
            break;
    }
}
void bubbleSortIndexed(int arr[],int a,int b) // sorting subArray from arr[a] to arr[b]
{
    int i,j,temp,n;
    n=b-a+1; // number of elements to be sorted
    for(i=0;i<n-1;i++)
    {
        for(j=a;j<b-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void bubbleSortImprovedIndexed(int arr[],int a,int b) // sorting subArray from arr[a] to arr[b]
{
    int i,j,temp,flag,n;
    n=b-a+1; // number of elements to be sorted
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=a;j<b-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int arr[]={3,8,1,23,7,9,24,6,12};
    int n=9,i;
    bubbleSortImprovedIndexed(arr,3,6);
    //bubbleSort(arr,n);
    for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
}
