#include<stdio.h>

int main()
{
    int t,answer;
    char c;
    FILE*f;
    f=fopen("a.txt","r");
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        while(1)
        {
            if(c=='\n')
                break;
            if(c=='a' || c=='e' ||c=='i'|| c=='o' ||c=='u')
                answer++;
        }
        printf("%d ",answer);
    }
    return 0;
}
