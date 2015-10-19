#include<stdio.h>
int comparisionFunction(const void * a,const void * b);

int main()
{
    long long int cost=0;
    int i,n,x,*arr;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int*)n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&x);
    qsort(arr,n,sizeof(int),comparisionFunction());
    for(i=0;i<n;i++)
        if(arr[i]<0)
            break;
    if(i!=n)
    {
        if(x*abs(arr[i]) <= abs(arr[i])*n)
        {
            cost+=x*abs(arr[i]);
            for(j=i;j<n;j++)
                arr[j]+=1;
        }
        else
        {
            cost++;
            arr[i]++;
        }
    }
}

int comparisionFunction(const void * a,const void * b)
{
    return strcmp((char*)a,(char*)b);
}
