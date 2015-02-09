#include<stdio.h>

int isPalindrome(char*s,int start,int end)
{
    int i,j;
    for(i=start,j=end;i<=(start+end)/2;i++,j--)
        if(s[i]!=s[j])
            return i;
    return -1; // returns -1 if the string is palindrome
}
int main()
{
    int t,isPalin,len;
    char s[100001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        len=strlen(s);
        if(len==2)
            printf("YES\n");
        else
        {

            isPalin=isPalindrome(s,0,len-1);
            if(isPalin==-1)
                printf("YES\n");
            else
            {
                if(isPalindrome(s,isPalin+1,len-isPalin-1)==-1 || isPalindrome(s,isPalin,len-isPalin-2)==-1)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
    return 0;
}
