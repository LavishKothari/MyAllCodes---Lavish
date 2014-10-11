#include <stdio.h>
int main()
{
    int t, n, c, answer,m,wrappers;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d%d%d",&n,&c,&m);
        answer=n/c;
        wrappers=n/c;
        while(1)
        {
            //printf("hello\n");
            //printf("n = %d\tc = %d\tm = %d\n",n,c,m);

            if(wrappers<m)
                break;
            //printf("hey\n\n");
            answer=answer+(wrappers/m);
            wrappers=wrappers%m+wrappers/m;
        }
        printf("%d\n",answer);
    }
    return 0;
}
