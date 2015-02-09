#include<stdio.h>
#include<string.h>
int F(char str[])
{
    int balance=0,maxBalance=0,i;
    for(i=0;str[i];i++)
    {
        if(str[i]=='(')
            balance++;
        else if(str[i]==')')
            balance--;
        maxBalance=maxBalance>balance?maxBalance:balance;
    }
    return maxBalance;
}
int main()
{
    int f,t,i;
    char str[100001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        f=F(str);
        for(i=0;i<f;i++)
            printf("(");
        for(i=0;i<f;i++)
            printf(")");
        printf("\n");
    }
    return 0;
}
