#include<stdio.h>

int main()
{
    int c,a,b;
    while(1)
    {
        scanf("%d%d",&a,&b);
        c=a%b;
        printf("answer is %d\n",c);
    }
    return 0;
}
