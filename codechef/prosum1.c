#include<stdio.h>
#include<stdlib.h>
int main()
{
    int flag,flag2,t,temp,element,n;
    long long int answer;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        answer=0;
        flag=flag2=0;

        answer=(long long int)n*(long long int)(n-1)/2;

        temp=n;

        while(temp--)
        {
            scanf("%d",&element);
            if(element==1 || element==0)
            {
                flag++;
                answer=answer-(n-flag);
            }
            if(element==2)
            {
                flag2++;
                answer=answer-flag2+1;
            }
        }

        printf("%lld\n",answer);
    }
    return 0;
}
