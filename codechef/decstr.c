#include<stdio.h>

void printRevString()
{
    int i;
    for(i=25;i>=0;i--)
        printf("%c",(i+97));
}
void printString(int n)
{
    int i;
    if(n<26)
    {
        for(i=n%26;i>=0;i--)
            printf("%c",(i+97));
        printf("\n");
        return;
    }
    else
    {
        for(i=n%26+1;i>=0;i--)
            printf("%c",(i+97));
    }
    while(n>=0)
    {
        if(n>=26)
        {
            printRevString();
            n-=25;
            continue;
        }

        n=-1;
    }
    printf("\n");
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printString(n);
    }
    return 0;
}
