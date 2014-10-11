#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t,n,cn,answer;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cn=n;
        answer=0;
        while(n)
        {
            while(n%10==0)
                n/=10;
            if(cn%(n%10)==0)
                answer++;
            n/=10;
        }
        printf("%d\n",answer);
    }
    return 0;
}
