#include<stdio.h>

int main()
{
    int i,answer,t,n;
    scanf("%d",&t);
    while(t--)
    {
        answer=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            if(i%2==0)
                answer*=2;
            else
                answer++;
        }
        printf("%d\n",answer);
    }
    return 0;
}
