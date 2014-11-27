#include<stdio.h>
#include<string.h>
int isPalindrome(char*arr)
{
    int i,j;
    for(i=0,j=strlen(arr)-1;i<=j;i++,j--)
        if(arr[i]!=arr[j])
            return 0;
    return 1;
}
int main()
{
    int t;
    char arr[100001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",arr);

        if(isPalindrome(arr))
            printf("1\n");
        else printf("2\n");
    }
    return 0;
}
