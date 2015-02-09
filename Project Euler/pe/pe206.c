#include<stdio.h>

int isInFormat(long long int n)
{
    if(n%10==9)
    {
        n/=100;
        if(n%10==8)
        {
            n/=100;
            if(n%10==7)
            {
                n/=100;
                if(n%10==6)
                {
                    n/=100;
                    if(n%10==5)
                    {
                        n/=100;
                        if(n%10==4)
                        {
                            n/=100;
                            if(n%10==3)
                            {
                                n/=100;
                                if(n%10==2)
                                {
                                    n/=100;
                                    if(n%10==1)
                                        return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    long long int i;
    for(i=101010100;i<138902663;i++)
    {
        if((i%10==3 || i%10==7)&&isInFormat(i*i))
        {
            printf("%d",(i*10));
            break;
        }
    }
    return 0;
}
