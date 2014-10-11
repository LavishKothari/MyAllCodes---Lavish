#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char str[10001];
    int t,answer,len,i,j;
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        scanf("%s",str);
        len=strlen(str);
        for(i=0,j=len-1;i!=j && i<=j ;i++,j--)
            answer+=abs(str[i]-str[j]);
        printf("%d\n",answer);
    }

    return 0;
}
