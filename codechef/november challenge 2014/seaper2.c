/*
    complete program for finding all the permutations of the number entered by the user.

    Features :
    1) Find permutation of the given number when all the digits are different.
    2) Find permutation of the given number when some digits are same.
    3) Find permutation when the number even contains zero eg. 2004.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int **numArr;

void swap(int*str,int index1,int index2)
{
    int temp;
    temp=str[index1];
    str[index1]=str[index2];
    str[index2]=temp;
}

int compare(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);
}
long long findFactorial(int n)
{
    long long fact=1,i;
    for(i=2;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}

long long findNumberOfPermutations(int str[],int len)
{
    long long int number,i;
    int flag[128];

    for(i=0;i<128;i++)
        flag[i]=0;
    for(i=0;i<len;i++)
        flag[str[i]]++;

    number=findFactorial(len);
    for(i=0;i<128;i++)
        if(flag[i]>1)
            number/=findFactorial(flag[i]);
    return number;
}

int findMinimum(int str[],int index1,int len)
{
    /*
        this function returns the index of minimum element in the array
        that is greater that element at index1 but minimum in the array from index1+1 till strlen(str)
    */
    int minIndex,i;
    int min=2147483647;
    for(i=index1+1;i<len;i++)
    {
        if(str[i]<min && str[i]>str[index1])
        {
            min=str[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void findNextPermutation(int str[],int len)
{
    int i,index1,index2;
    for(i=len-1;i>=0;i--)
        if(str[i-1]<str[i])
            break;

    index1=i-1;
    index2=findMinimum(str,index1,len);
    swap(str,index1,index2);
    qsort(str+index1+1,len-index1-1,sizeof(int),compare);
}
int countDigits(long long int n)
{
    int answer=0;
    while(n)
    {
        answer++;
        n/=10;
    }
    return answer;
}
int *formArray(long long int n)
{
    int len,*arr,i;
    len=countDigits(n);
    arr=(int*)malloc(sizeof(int)*len);
    for(i=len-1;i>=0;i--)
    {
        arr[i]=n%10;
        n/=10;
    }
    return arr;
}
long long int formNumber(int *arr,int len)
{
    long long int answer=0;
    int i;
    for(i=0;i<len;i++)
        answer=answer*10+arr[i];
    return answer;
}
int isMatchingPairPresent(long long int n)
{
    int *arr,len=countDigits(n);
    for(i=0;i<len;i++)
    {
        arr=formArray(n);
        temp=arr[i];
        for(j=0;j<len;j++)
        {
            if(j!=i&&arr[j]>temp)
                arr[j]--;
        }
        num=0;
        for(j=0;j<len;j++)
            if(j!=i)
                num=num*10+arr[j];

    }
}
long long int printPermutations(long long int n)
{
    int i,*arr,len;
    long long numberOfPermutations;
    arr=formArray(n);
    len=countDigits(n);
    numberOfPermutations=findNumberOfPermutations(arr,len);
    qsort((void*)arr,len,sizeof(int),compare);
    for(i=0;i<numberOfPermutations;i++)
    {
        n=formNumber(arr,len);
        printf("%d -> %d\n",i+1,n);
        if(isMatchingPairPresent(n))
            return n;
        if(i==numberOfPermutations-1)
            break;
        findNextPermutation(arr,len);
    }
}


int main()
{
    long long int n;



    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        numArr=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
        {
            num=0;
            for(int j=0;j<n-1;j++)
            {
                scanf("%d",&temp);
                num=num*10+temp;
            }
            numArray[i]=num;
        }
        printPermutations(n);
    }
    return 0;
}
