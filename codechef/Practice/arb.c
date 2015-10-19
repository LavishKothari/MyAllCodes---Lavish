#include<stdio.h>

void fun(int a)
{
    while(a)
    {
        printf("b\n");
        return;
    }
    printf("a\n");

}
int main()
{
    int a;
    scanf("%d",&a);
    fun(a);
    return 0;
}
