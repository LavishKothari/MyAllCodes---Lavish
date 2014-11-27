#include<stdio.h>
#include<stdlib.h>

int findAnswer(int n)
{
    int arr[11],len,numberOfZero=0;

    int i;
    int min[11];
    if(n==0)
        return 0;
    /******/
    len=0;
    numberOfZero=0;
    if(n==0)
        numberOfZero++;
    while(n)
    {
        arr[len]=n%10;
        if(arr[len]==0)
            numberOfZero++;
        len++;
        n/=10;
    }
    /************/

    if(len==1)
        return 1-numberOfZero;

    min[len-1]=1;
    i=len-1;
    if(arr[i]*10+arr[i-1]<=26 && arr[i]*10+arr[i-1]>0)
        min[len-2]=2;
    else
        min[len-2]=1;

    for(i=len-3;i>=0;i--)
    {
        min[i]=min[i+1];
        if(arr[i+1]*10+arr[i]<=26 && arr[i+1]*10+arr[i]>0)
            min[i]+=min[i+2];
    }

    /*
    for(i=0;i<len;i++)
        printf("%d",arr[i]);
    */

    return min[0]-numberOfZero;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",findAnswer(n));
    }
    return 0;
}
