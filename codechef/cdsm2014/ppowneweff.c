#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int arrlen,answer;
long long int* multiply(long long int *arr,int n)
{
    long long int temp=100000000000000000;
    int i,originalLen;
    if(arrlen==0)
    {
        arr=(long long int*)malloc(sizeof(long long int ));
        arr[0]=n;
        arrlen=1;
        return arr;
    }
    originalLen=arrlen;
    for(i=0;i<originalLen;i++)
        arr[i]*=n;
    for(i=0;i<originalLen;i++)
    {
        if((int)log10(arr[i])+1==18)
        {
            if(i==originalLen-1)
            {
                arr=(long long int*)realloc(arr,sizeof(long long int)*(arrlen+1));
                arrlen++;
                arr[i+1]=0;
            }
            arr[i+1]+=arr[i]/temp;
            arr[i]=arr[i]%temp;
        }
    }
    return arr;
}
int sumDigits(long long int n)
{
    int answer=0;
    while(n)
    {
        answer+=n%10;
        n/=10;
    }
    return answer;
}
int main()
{
    int i,a,b,t,z;
    long long int*arr;

    scanf("%d",&t);
    for(z=1;z<=t;z++)
    {
        scanf("%d%d",&a,&b);
        if(a==1)
        {
            printf("Case %d: 1\n",z);
            continue;
        }
        arrlen=0;
        answer=0;
        arr=NULL;
        for(i=0;i<b;i++)
            arr=multiply(arr,a);
        for(i=0;i<arrlen;i++)
            answer+=sumDigits(arr[i]);
        if(b==0)
            printf("Case %d: 1\n",z);
        else printf("Case %d: %d\n",z,answer);
        if(arr)
            free(arr);
    }
    return 0;
}
