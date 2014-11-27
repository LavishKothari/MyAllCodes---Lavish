#include<stdio.h>
int isPalindrome(char*s,int a,int b)
{
    int j,i;
    for(i=a,j=b;i<j;i++,j--)
        if(s[i]!=s[j])
            return 0;
    return 1;
}
int main()
{
    int t,answer,i,j,len;
    int primes[100001]={0}; // initializing the array initially to 0.
    char s[100001];
    primes[0]=primes[1]=1;
    for(i=2;i<=100000;i++)
        if(!primes[i]) // means i is prime
            for(j=2*i;j<=100000;j+=i)
                primes[j]=1;

    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        scanf(" %s",s);
        len=strlen(s);
        for(i=0;i<len;i++)
            for(j=i+1;j<len;j++)
                if((!primes[j-i+1]) && isPalindrome(s,i,j))
                    answer++;
        printf("%d\n",answer);
    }
    return 0;
}
