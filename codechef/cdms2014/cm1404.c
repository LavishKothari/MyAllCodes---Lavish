#include<stdio.h>
#include<math.h>

int isPerfectSquare(int n)
{
    int a;
    a=(int )sqrt(n);
    if(a*a==n)
        return 1;
    return 0;
}

int findAnswer(int x)
{
    int a,answer;
    if(isPerfectSquare(8*x-7))
    {
        answer=((int)sqrt(8*x-7)-1)/2;
    }
    else
    {
        answer=((int)sqrt(8*x-7)-1)/2;
        answer++;
    }
    return answer;
}

int main()
{
    int t,n,answer;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        answer=findAnswer(n);
        printf("%d\n",answer);
    }
    return 0;
}
