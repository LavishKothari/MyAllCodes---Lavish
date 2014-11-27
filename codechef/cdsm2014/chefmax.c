#include<stdio.h>
#include<string.h>

void findAnswer(char*str)
{
    int flag[26]={0},len,max,maxi,i;

    for(i=0;str[i];i++)
        flag[str[i]-'a']++;

    max=0;
    for(i=0;i<26;i++)
        if(flag[i]>max)
        {
            maxi=i;
            max=flag[i];
        }
    for(i=0;str[i];i++)
        if(str[i]==maxi+'a')
            str[i]='?';
}
int main()
{
    int t;
    char str[1001];
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s",str);
        findAnswer(str);
        printf("%s\n",str);
    }
    return 0;
}
