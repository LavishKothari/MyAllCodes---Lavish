#include<stdio.h>

int main()
{
    int i,a,b,c;
    a=0;b=1;
    i=2;
    while(1)
    {
        c=a+b;
        i++;
        printf("%d\t->\t%d\n",i,c);
        if(c<b)
            break;
        a=b;
        b=c;
    }
    printf("\nThe first term that cant be accomodated in integer's range is : %d\n",i);
    return 0;
}
