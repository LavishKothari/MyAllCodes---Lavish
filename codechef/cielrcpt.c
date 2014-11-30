#include<stdio.h>

int main()
{
    int t,p,answer;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&p);
        answer=p/2048;
        p%=2048;
        while(p)
        {
            if(p&1==1)
                answer++;
            p=p>>1;
        }
        printf("%d\n",answer);
    }
    return 0;
}
