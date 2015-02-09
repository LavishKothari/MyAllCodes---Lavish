#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
    return answer;
}

int compare1(const void *a,const void *b)
{
    return strcmp((char*)b,(char*)a); // sorting in descending order
}
int compare2(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b); // sorting in ascending order
}
int containsSameDigits(long long int a,long long int b)
{
    int flag1[10],flag2[10],i;
    for(i=0;i<10;i++)
        flag1[i]=flag2[i]=0;
    while(a)
    {
        flag1[a%10]++;
        a/=10;
    }
    while(b)
    {
        flag2[b%10]++;
        b/=10;
    }
    for(i=0;i<10;i++)
        if(flag1[i]!=flag2[i])
            return 0;
    return 1;
}
void bubbleSortAscending(int *arr,int n)
{
    int i,j,flag,temp;
    for(i=1;i<n;i++)
    {
        flag=0;
        for(j=0;j<n-i;j++)
            if(arr[j]>arr[j+1])
            {
                flag=1;

                temp=arr[j];
                arr[j]=arr[j+1] ;
                arr[j+1]=temp;
            }

        if(flag==0)
            break;
    }
}
void bubbleSortDescending(int *arr,int n)
{
    int i,j,flag,temp;
    for(i=1;i<n;i++)
    {
        flag=0;
        for(j=0;j<n-i;j++)
            if(arr[j]<arr[j+1])
            {
                flag=1;

                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        if(flag==0)
            break;
    }
}
int isSatisfyingCondition(long long int n)
{
    int *arr,len,start,end,counter;
    long long int n1,n2,i;
    len=countDigits(n);
    arr=(int*)malloc(sizeof(int)*len);
    arr=formArray(n);
    bubbleSortDescending(arr,len);
    n2=formNumber(arr,len);
    bubbleSortAscending(arr,len);
    n1=formNumber(arr,len);
    free(arr);
    start=(int)pow(n1,1/3.0);
    start--;
    end=(int)pow(n2,1/3.0);
    end++;
    counter=0;
    for(i=start;i<=end;i++)
    {
        if(containsSameDigits(i*i*i,n) && isPerfectCube(i*i*i))
        {
            printf("%lld\n",(i*i*i));
            counter++;
        }
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
        printf("i = %d\n",i);
        if(isSatisfyingCondition(i*i*i))
        {
            printf("\nanswer = %d\n",i);
            break;
        }
    }
    return 0;
}
