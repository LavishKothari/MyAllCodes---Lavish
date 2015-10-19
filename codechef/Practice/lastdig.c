#include<stdio.h>
int arr[1000000]={0};
int s(int n)
{
    int answer=0;
    int cn=n;
    while(n)
    {
        if(n<1000000 && arr[n]!=0)
        {
            answer+=arr[n];
            break;
        }

        if(n&1==1)// means last digit of n is odd
            answer+=n%10;
        else
            answer+=((n%10)*2);
        n/=10;
    }
    if(cn<1000000 && arr[n]==0)
        arr[n]=answer;
    return answer;
}
int d(int n)
{
    return s(n)%10;
}
int main()
{
    int t,a,b,i;
    long long int sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d",&a,&b);
        for(i=a;i<=b;i++)
        {
            if(i<1000000 && arr[i]!=0)
                sum+=arr[i];
            else
                sum+=d(i);
        }
        printf("%d\n",sum);
    }
    return 0;
}
