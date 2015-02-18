#include<stdio.h>

int main()
{
    int t,answer,i;
    char str[100001];
    char c;
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        scanf(" %[^\n]s",str);
        for(i=0;str[i];i++)
        {
        	c=str[i];
            if(c=='a' || c=='e' ||c=='i'|| c=='o' ||c=='u' || c=='y')
                answer++;
        }
        printf("%d ",answer);
    }
    return 0;
}
