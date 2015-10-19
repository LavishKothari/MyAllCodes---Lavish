#include<stdio.h>
#include<string.h>

int isPrime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    char str[13];
    int t,len;
    while(t--)
    {
        scanf("%s",str);
        len=strlen(str);
        for(i=len-1;i>=0;i++)
        {
            if(str[i]=='?')
            {

            }
        }
    }
}
