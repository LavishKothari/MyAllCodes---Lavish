#include<stdio.h>
#include<math.h>
long long int answer=0;

void compromise(int*arr,int a,int b)
{
    int pro=abs(a-b);
    if(arr[a]>0)
    {
        if(arr[a]>abs(arr[b]))
        {
            arr[a]=arr[a]+arr[b];
            answer+=abs(arr[b])*pro;
            arr[b]=0;
        }
        else if(arr[a]<abs(arr[b]))
        {
            arr[b]=arr[b]+arr[a];
            answer+=arr[a]*pro;
            arr[a]=0;
        }
        else
        {
            answer+=arr[a]*pro;
            arr[a]=arr[b]=0;
        }
    }
    else
    {
        if(arr[b]>abs(arr[a]))
        {
            arr[b]=arr[b]+arr[a];
            answer+=abs(arr[a])*pro;
            arr[a]=0;
        }
        else if(arr[b]<abs(arr[a]))
        {
            arr[a]=arr[a]+arr[b];
            answer+=arr[b]*pro;
            arr[b]=0;
        }
        else
        {
            answer+=arr[b]*pro;
            arr[b]=arr[a]=0;
        }
    }
}
int isArrayNegativeFromFront(int *arr,int n)
{
    int i;
    for(i=0;i<n && arr[i]==0;i++);
    if(i==n || arr[i]>0)
        return -1;
    return i;
}

int isArrayNegativeFromBack(int *arr,int n)
{
    int i;
    for(i=n-1;i>=0 && arr[i]==0;i--);
    if(i==-1 || arr[i]>0)
        return -1;
    return i;
}

int isArrayPosetiveFromFront(int *arr,int n)
{
    int i;
    for(i=0;i<n && arr[i]==0;i++);
    if(i==n || arr[i]<0)
        return -1;
    return i;
}

void removeNegativeFromFront(int*arr,int n)
{
    int index,i;
    while((index=isArrayNegativeFromFront(arr,n))!=-1)
    {
        for(i=index+1;i<n && arr[index]!=0;i++)
        {
            if(arr[i]>0)
            {
                compromise(arr,index,i);
            }
        }
    }
}

void removeNegativeFromBack(int*arr,int n)
{
    int index,i;
    while((index=isArrayNegativeFromBack(arr,n))!=-1)
    {
        for(i=index-1;i>=0 && arr[index]!=0;i--)
        {
            if(arr[i]>0)
            {
                compromise(arr,index,i);
            }
        }
    }
}
void removePosetiveFromFront(int*arr,int n)
{
    int index,i;
    while((index=isArrayPosetiveFromFront(arr,n))!=-1)
    {
        for(i=index+1;i<n && arr[index]!=0;i++)
        {
            if(arr[i]<0)
            {
                compromise(arr,index,i);
            }
        }
    }
}


void printArray(int*arr,int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int arrayContainsNonZero(int*arr,int n)
{
    int i;
    for(i=n-1;i>=0;i--)
        if(arr[i]!=0)
            return 1;
    return 0;
}
int main()
{
    int t,n,*arr,i;
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        scanf("%d",&n); // n is the length of the array.
        arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        while(arrayContainsNonZero(arr,n))
        {
            removeNegativeFromFront(arr,n);
            removeNegativeFromBack(arr,n);
            removePosetiveFromFront(arr,n);
            //printArray(arr,n);
        }
        //printArray(arr,n);
        printf("%lld\n",answer);
    }
    return 0;
}
