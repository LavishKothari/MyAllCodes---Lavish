#include<stdio.h>
#include<math.h>
int main()
{
    float l,d,s,c;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%f%f%f%f",&l,&d,&s,&c);
        if(l-s*pow(c+1,d-1)<=0)
            printf("ALIVE AND KICKING\n");
        else
            printf("DEAD AND ROTTING\n");
    }
    return 0;
}
