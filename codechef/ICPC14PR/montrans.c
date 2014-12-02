#include<stdio.h>

int main()
{
    int t,a,b,c,temp,max,answer,counter;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        max=a*100+b;
        counter=0;
        answer=0;
        while(a*100+b>c && counter<=10000)
        {
            counter++;
            if(b>=c)
            {
                b-=c;
            }
            else
            {
                a--;
                b+=100;
                b-=c;
            }
            temp=b;
            b=a;
            a=temp;
            if(a*100+b > max)
            {
                answer=counter;
                max=a*100+b;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
