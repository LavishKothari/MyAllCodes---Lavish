#include<stdio.h>

int main()
{
    int change,n,a,b,max1=0,max2=0,scorea=0,scoreb=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        scorea+=a;
        scoreb+=b;
        change=scorea-scoreb;
        if(change<0)
        {
            change=-change;
            if(max2<change)
                max2=change;
        }
        else if(change>0)
        {
            if(max1<change)
                max1=change;
        }
    }
    if(max1>max2)
        printf("1 %d\n",max1);
    else if(max2>max1)
        printf("2 %d\n",max2);
    else
    {
        if(scorea>scoreb)
            printf("1 %d\n",max1);
        else
            printf("2 %d\n",max2);
    }
    return 0;
}
