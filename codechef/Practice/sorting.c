#include<stdio.h>
#include<stdlib.h>
//int concatenate(int*,int,int,int*,int);
int append(int*,int,int);
void sort(int*,int);
long long int comparision_count=0;
int main()
{
    int i,n,*arr,len;
    scanf("%d",&len);
    arr=(int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++)
        scanf("%d",&arr[i]);

    sort(arr,len);
    printf("%lld",comparision_count);
    free(arr);
    return 0;
}
void sort(int*arr,int length)
{
    int i,*less,*greater,pivot,lessLen=0,greaterLen=0;
    less=NULL;
    greater=NULL;
    less=(int *)malloc(sizeof(int)*length);
    greater=(int*)malloc(sizeof(int)*length);
    if(length<=1)
        return ;
    pivot=arr[(length+1)/2 - 1];
    for(i=0;i<length;i++)
    {
        comparision_count++;
        if(arr[i]<pivot)
        {
            lessLen++;
            less[lessLen-1]=arr[i];
        }
        else if(arr[i]>pivot)
        {
            greaterLen++;
            greater[greaterLen-1]=arr[i];
        }
    }
    sort(less,lessLen);
    sort(greater,greaterLen);
    free(less);
    free(greater);
}
