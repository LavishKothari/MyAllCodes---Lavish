#include<stdio.h>
#include<math.h>
int main()
{
    int t,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&f);
        printf("%d ",(int)round((f-32)*5/9.0));
    }
    return 0;
}
