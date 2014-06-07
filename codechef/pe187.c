#include<stdio.h>
int containsTwoFactors(int );
int main()
{
    int n,answer=0,i;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        answer+=containsTwoFactors(i);

    }

    printf("answer = %d",answer);
    return 0;
}
int containsTwoFactors(int n)
{
    int counter=0,i,temp,product=1;
    temp=n;
    for(i=2;i<=temp/2;i++)
    {
        while(n%i==0)
        {
            product*=i;
            n/=i;

            counter++;
            if(counter>2)
                return 0;
            if(product==temp && counter==2)
            {
                return 1;
            }
            if(product==temp && counter!=2)
            {
                return 0;
            }
        }
    }
    if(counter==2)
        return 1;
    else return 0;
}
