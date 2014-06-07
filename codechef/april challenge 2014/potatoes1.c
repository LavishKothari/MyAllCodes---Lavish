#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i,t,x,y,*ans,counter;
    scanf("%d",&t);
    ans=(int*)malloc(sizeof(int)*t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        for(counter=1;;counter++)
        {
            if(isPrime(x+y+counter))
            {
                ans[i]=counter;
                break;
            }
        }

    }
    for(i=0;i<t;i++)
        printf("%d\n",ans[i]);
    return 0;
}

int isPrime(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
