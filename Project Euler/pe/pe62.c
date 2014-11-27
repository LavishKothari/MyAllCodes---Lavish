/*
    TLE :(
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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

int isPerfectCube(long long int n)
{
    long long int a;
    a=((long long int)pow(n,1/3.0));
    //printf("a = %d\n",a);
    if(a*a*a==n)
        return 1;
    a++;
    if(a*a*a==n)
        return 1;
    return 0;
}
long long int formNumber(int *arr,int len)
{
    long long int answer=0;
    int i;
    for(i=0;i<len;i++)
        answer=answer*10+arr[i];
    //printf("answer = %d\n",answer);
    return answer;
}
int isSatisfyingCondition(long long int n)
{
    int i,counter=0,*arr,len;
    long long numberOfPermutations;
    arr=formArray(n);
    len=countDigits(n);
    numberOfPermutations=findNumberOfPermutations(arr,len);
    qsort((void*)arr,len,sizeof(int),compare);
    for(i=0;i<numberOfPermutations;i++)
    {
        n=formNumber(arr,len);
        //printf("%d -> %lld\n",i+1,n);
        if(isPerfectCube(n) && countDigits(n)==len)
        {
            printf("perfect cube = %lld\n",n);
            counter++;
        }
        if(i==numberOfPermutations-1)
            break;
        findNextPermutation(arr,len);
    }
    if(counter==5)
        return 1;
    return 0;
}
int main()
{
    long long int i;
    for(i=1;;i++)
    {
        printf("%d\n",i);
        if(isSatisfyingCondition(i*i*i))
        {
            printf("\nanswer = %d\n",i);
            break;
        }
    }

    //isSatisfyingCondition(5204699837);
    return 0;
}
