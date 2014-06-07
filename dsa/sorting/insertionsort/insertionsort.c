#include<stdio.h>
#include<stdlib.h>

void insertionSort(int*,int);

int main()
{
    int *a,n,i;
    printf("Enter the number of elements that you want to sort : ");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("Enter the elements that you want to sort : \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertionSort(a,n);
    printf("Your sorted array is : \n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
// function for insertion sort
void insertionSort(int*arr,int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        for(j=i-1;j>=0 && arr[j]>key;j--)
            arr[j+1]=arr[j];
        arr[j+1]=key;
    }
}
