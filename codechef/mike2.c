#include<stdio.h>
#include<stdlib.h>
int comparisionFunction(const void * a,const void * b);

int main()
{
    long long int i,counter=0,n,x,element,sum=0,failed,succeded=0,*arr;
    scanf("%lld%lld",&n,&x);
    arr=(long long int*)malloc(sizeof(long long int)*n);

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    qsort(arr,n,sizeof(long long int),comparisionFunction);
    failed=n;
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
            counter+=arr[i]/2;
        else
            counter+=(arr[i]/2+1);
        if(counter>x)
            break;
        failed--;
    }
    if(i!=n)
    {
        if(arr[i]%2==0)
            counter-=arr[i]/2;
        else
            counter-=(arr[i]/2+1);
    }
    succeded=0;
    for(i=0;i<n;i++)
    {
        counter+=arr[i]/2;
        if(counter>x)
            break;
        succeded++;
    }
    printf("%lld %lld\n",failed,succeded);
    return 0;
}

int comparisionFunction(const void * a,const void * b)
{
    return strcmp((char*)a,(char*)b);
}
