#include<stdio.h>

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n%2==0)
            printf("ALICE\n");
        else
            printf("BOB\n");
    }
    return 0;
}
