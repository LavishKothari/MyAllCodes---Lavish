#include<stdio.h>
#include<stdlib.h>

long long int binarySearch(long long int*,long long int,long long int);
int comparisionFunction(const void * a,const void * b);
long long int findLeast(long long int*,long long int);
long long int main()
{
    long long int count[10000],number[10000],sortedNumber[10000],answer;
    char name[10000][6];
    long long int t,n,i,location;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",name[i]);
            scanf("%lld",&number[i]);
            sortedNumber[i]=number[i];
        }
        qsort(sortedNumber,n,sizeof(long long int),comparisionFunction);

        answer=findLeast(sortedNumber,n);

        if(answer==-1)
            printf("Nobody wins.\n");
        else
        {

            location=binarySearch(number,n,answer);
            printf("%s\n",name[location]);
        }
    }
}

int comparisionFunction(const void * a,const void * b)
{
    return strcmp((char*)a,(char*)b);
}

long long int findLeast(long long int*arr,long long int n)
{
    long long int i,counter,temp,answer;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            counter=0;
            temp=arr[i];
            continue;
        }
        else
        {
            if(temp==arr[i])
                counter++;
            else
            {
                if(counter==0)
                    return temp;
                else
                    counter=0;
            }
        }
        temp=arr[i];
    }
    if(counter==0)
        return arr[i-1];
    else
        return -1;
}

long long int binarySearch(long long int*a,long long int n,long long int v)
{
    long long int i;
    for(i=0;i<n;i++)
        if(a[i]==v)
            return i;
    return -1;
}
