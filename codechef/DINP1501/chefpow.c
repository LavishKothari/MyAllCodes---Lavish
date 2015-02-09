#include<stdio.h>
int main()
{
    int a,counter=0;
    scanf("%d",&a);
    for(;a;counter++,a>>=1)
        if((a&1)==1)
            printf("%d ",(1<<counter));
    return 0;
}
