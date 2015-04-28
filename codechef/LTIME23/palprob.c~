#include<stdio.h>
#include<string.h>
int isPalindrome(char str[],int a,int b)
{
    int i,j;
    for(i=a,j=b;i<j;i++,j--)
        if(str[i]!=str[j])
            return 0;
    return 1;
}
long long int pal(char str[],int a,int b)
{
    //printf("a,b = %d %d\n",a,b);
    int len;
    if(isPalindrome(str,a,b)==0)
        return 0;
    if(b==a)
        return 1;
    len=b-a+1;
    return 1+pal(str,a,a+len/2-1);
}
long long int calculate(char str[])
{
    int i,j;
    long long int sum=0;
    for(i=0;str[i];i++)
    {
        for(j=i;str[j];j++)
        {
            sum+=pal(str,i,j);
        }
    }
    return sum;
}
int main()
{
    int t;
    char str[100001];
    //printf("%lld\n",pal("aba",0,2));
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s",str);
        printf("%lld\n",calculate(str));
    }
    return 0;
}
