#include<stdio.h>

void printFactorial(int n)
{
    int i,factorial=1;
    for(i=1;i<=n;i++)
        factorial*=i;
    printf("%d\n",factorial);
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printFactorial(n);
    }
    return 0;
}
