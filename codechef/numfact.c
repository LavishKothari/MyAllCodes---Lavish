#include<stdio.h>
int arr[1000000];
void updateArray(int);
int main()
{
    int t,n,element,i;
    long long int sum;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<1000000;i++)
        {
            arr[i]=0;
        }
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&element);
            updateArray(element);
        }
        sum=1;
        for(i=0;i<1000000;i++)
        {
            sum*=(arr[i]+1);
        }

        printf("%lld\n",sum);
    }
}

void updateArray(int n)
{
    int i;
    for(i=2;i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            arr[i]++;
        }
    }
}
