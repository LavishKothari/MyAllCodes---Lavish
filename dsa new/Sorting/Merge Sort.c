#include<stdio.h>
#include<stdlib.h>
/*
    the merge procedure merges the two sorted sub arrays
    the arrays are :
        1. arr[p]...arr[q]
        2. arr[q]...arr[r]
*/
void merge(int arr[],int p,int q,int r)
{
    int *left,*right,n,maxInt=2147483647,len1,len2,i,j,k;
    len1=q-p+1;
    len2=r-q;
    left=(int*)malloc(sizeof(int)*(len1+1));
    right=(int*)malloc(sizeof(int)*(len2+1));
    for(i=p;i<=q;i++)
        left[i-p]=arr[i];
    left[i-p]=maxInt;
    for(i=q+1;i<=r;i++)
        right[i-q-1]=arr[i];
    right[i-q-1]=maxInt;
    for(i=p,j=0,k=0;i<=r;i++)
    {
        if(left[j]<right[k])
            arr[i]=left[j++];
        else
            arr[i]=right[k++];
    }
    free(left);
    free(right);
}
void mergeSort(int arr[],int a,int b) // the merge sort is already indexed.
{
    int mid;
    if(a<b)
    {
        mid=(a+b)/2;
        mergeSort(arr,a,mid);
        mergeSort(arr,mid+1,b);
        merge(arr,a,mid,b);
    }
}

int main()
{
    int arr[]={3,8,1,23,7,9,10,24,6,12};
    int n=10,i;
    mergeSort(arr,0,n-1);
    for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
}
