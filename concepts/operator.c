/*
    as the associativity of operators * is from left to right
\*/
#include<stdio.h>

int x;
int fun()
{
    x++;
    return 10;
}
int main()
{
    int y;
    x=5;
    y=fun()*x;
    printf("%d\n",y);
    return 0;
}
