#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char*str,int index1,int index2)
{
    char temp;
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

long long findNumberOfPermutations(char str[])
{
    long long number,repetition,*flag,i;

    flag=(int*)malloc(sizeof(int)*128);
    for(i=0;i<128;i++)
        flag[i]=0;
    for(i=0;str[i];i++)
        flag[str[i]]++;

    number=findFactorial(strlen(str));
    for(i=0;i<128;i++)
        if(flag[i]>1)
            number/=findFactorial(flag[i]);
    return number;
}

int findMinimum(char str[],int index1)
{
    /*
        this function returns the index of minimum element in the array
        that is greater that element at index1 but minimum in the array from index1+1 till strlen(str)
    */
    int minIndex,i;
    int min=2147483647;
    for(i=index1+1;i<strlen(str);i++)
    {
        if(str[i]<min && str[i]>str[index1])
        {
            min=str[i];
            minIndex=i;
        }
    }
    return minIndex;
}


void findNextPermutation(char str[])
{
    int i,index1,index2;
    for(i=strlen(str)-1;i>=0;i--)
        if(str[i-1]<str[i])
            break;

    index1=i-1;
    index2=findMinimum(str,index1);
    swap(str,index1,index2);
    qsort(str+index1+1,strlen(str)-index1-1,sizeof(char),compare);
}
int isNonIncreasing(char*str)
{
    int i;
    for(i=strlen(str)-1;i>0;i--)
        if(str[i]>str[i-1])
            return 1;
    return 0;
}
int main()
{
    int t;
    char str[101];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        if(isNonIncreasing(str))
        {
            findNextPermutation(str);
            printf("%s\n",str);
        }
        else
            printf("no answer\n");

    }
    return 0;
}
