#include<stdio.h>
int main()
{
    int t,flag[26],i,answer;
    char arr[100001];
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        for(i=0;i<26;i++)
            flag[i]=0;
        scanf("%s",arr);
        for(i=0;arr[i];i++)
            flag[arr[i]-'a']++;

        for(i=0;i<26;i++)
            if(flag[i]!=0)
                answer++;
        printf("%d\n",answer);
    }
    return 0;
}
