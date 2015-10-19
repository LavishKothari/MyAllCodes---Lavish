#include<stdio.h>
#include<string.h>
int isLapin(int *a,int *b)
{
    int i;
    for(i=0;i<26;i++)
        if(a[i]!=b[i])
            return 0;
    return 1;
}
int main()
{

    int t,flag1[26]={0},flag2[26]={0},i,len,s1,s2;
    char s[1001];
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<26;i++)
            flag1[i]=flag2[i]=0;
        scanf(" %s",s);
        len=strlen(s);
        if(len%2==0)
        {
            s1=len/2-1;
            s2=s1+1;
        }
        else
        {
            s1=len/2-1;
            s2=s1+2;
        }
        for(i=0;i<=s1;i++)
        {
            flag1[s[i]-'a']++;
        }
        for(i=s2;i<len;i++)
        {
            flag2[s[i]-'a']++;
        }
        if(isLapin(flag1,flag2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
