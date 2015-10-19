#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#define N 1000000
int isPrime(long long int);
int main()
{
    long long int i,counter=0,*arr;
    arr=NULL;
    for(i=2;;i++)
        if(isPrime(i))
        {
            counter++;
            arr=(long long int*)realloc(arr,sizeof(long long int )*counter);
            arr[counter-1]=i;
            if((i*2)>N)
                break;
            //printf("%lld\n",arr[counter-1]);
        }

    for(i=0;i<counter;++i)
        printf("%lld --> %lld\n",i,arr[i]);

    return 0;
}

int isPrime(long long int n)
{
    long long int i;
    for(i=2;i<=(long long int)sqrt(n);++i)
        if(n%i==0)
            return 0;
    return 1;
}
