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
        temp=n;
        while(temp--)
        {
            scanf("%d",&element);
            if(element==1 || element==0)
                flag++;
            if(element==2)
                flag2++;
        }

        if(flag || flag2>1)
        {
            answer+=(long long int)(n-flag)*(long long int)(n-flag-1)/2;
            answer-=(long long int)flag2*(long long int)(flag2-1)/2;
        }
        else
            answer=(long long int)n*(long long int)(n-1)/2;

        printf("%lld\n",answer);
    }
    return 0;
}
