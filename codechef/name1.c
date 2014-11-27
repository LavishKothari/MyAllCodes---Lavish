#include<stdio.h>
#include<string.h>
int isAnagram(char*a,char*b)
{
    int flag1[26]={0},flag2[26]={0},i;
    int lena,lenb;
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lena;i++)
        flag1[a[i]-'a']++;
    for(i=0;i<lenb;i++)
        flag2[b[i]-'a']++;
    for(i=0;i<26;i++)
        if(flag1[i]<flag2[i])
            return 0;
    return 1;
}
int main()
{
    int t,n,i;
    char a[80002],b[40001],c[80002],temp[40001];
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s %s",a,b);
        strcat(a,b);
        scanf("%d",&n);
        scanf(" %s",c);
        for(i=0;i<n-1;i++)
        {
            scanf(" %s",temp);
            strcat(c,temp);
        }
        if(isAnagram(a,c))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
