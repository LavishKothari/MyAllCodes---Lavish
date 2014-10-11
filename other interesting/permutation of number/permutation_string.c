#include<stdio.h>
#include<stdlib.h>

int countDigits(int n)
{
    int answer=0;
    while(n)
    {
        answer++;
        n/=10;
    }
    return answer;
}

long long int findFactorial(int n)
{
    int i;
    long long int factorial=1;
    for(i=1;i<=n;i++)
        factorial*=i;
    return factorial;
}

int *formArray(int n)
{
    int *arr,i;
    int len;
    len=countDigits(n);
    arr=(int*)malloc(sizeof(int)*len);
    for(i=len-1;i>=0;i--)
    {
        arr[i]=n%10;
        n/=10;
    }
    return arr;
}

void bubbleSort(int *arr,int start,int end)
{
    /*
        this function sorts the array elements between indices
        start and end of the array arr.

        The sorting algorithm applied here is Bubble Sort.
    */
    int i,j,temp,n;
    n=end-start+1;
    for(i=1;i<n;i++)
        for(j=start;j<end+1-i;j++)
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}
int findMinimum(int*arr,int start,int end,int n)
{
    /*
        this function returns the index of minimum number which is in the array 'arr'
        and between the index start and end.
    */
    int i,index,min;
    min=arr[start];
    index=start;

    for(i=start;i<=end;i++)
        if(min>arr[i] && arr[i]>n)
        {
            min=arr[i];
            index=i;
        }
    return index;
}
int findNextPermutation(int n)
{
    /*
        index1 and index2 are the elements to be swapped
    */
    int index1,index2,len,i,*arr,result=0,temp;

    len=countDigits(n);
    arr=formArray(n);
    for(i=len-1;i>0;i--)
        if(arr[i]>arr[i-1])
            break;
    index1=i-1;
    index2=findMinimum(arr,index1+1,len-1,arr[index1]);

    //printf("\n%d,%d\n",index1,index2);
    temp=arr[index1];
    arr[index1]=arr[index2];
    arr[index2]=temp;

    bubbleSort(arr,index1+1,len-1);

    for(i=0;i<len;i++)
        result=result*10+arr[i];
    return result;
}
void printPermutation(int n)
{
    long long int i;
    int answer=0,*arr,len;
    len=countDigits(n);
    arr=formArray(n);
    bubbleSort(arr,0,len-1);
    for(i=0;i<len;i++)
        answer=answer*10+arr[i];
    n=answer;
    for(i=0;i<findFactorial(len);i++)
    {
        printf("%lld -> %d\n",(i+1),n);
        n=findNextPermutation(n);
    }
}
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    printPermutation(n);
    return 0;
}
