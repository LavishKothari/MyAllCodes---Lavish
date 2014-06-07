#include<stdio.h>

int main()
{
    int n,tmp,i;
    for(i=0;;i++)
    {
        scanf("%d",&n);
        if(i==0)
        {
            tmp=n;
            continue;
        }
        printf("%d\n",tmp);
        if(n==42)
            break;

        tmp=n;
    }
    return 0;
}
