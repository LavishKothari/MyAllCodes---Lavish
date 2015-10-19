#include<stdio.h>
int isAnInteger(float f);
int main()
{
    int A,B,C,temp;
    float sum,a;
    int n,k,d,answer=0,i;
    scanf("%d%d%d",&n,&k,&d);

    temp=n;
    for(A=1;A<=temp;A++)
        for(B=1;B<=temp;B++)
            for(C=1;C<=temp;C++)
            {
                    n=A;
                    k=B;
                    d=C;
    for(i=1;i<=d;i++)
    {
        a=(2*n-k*i*(k-1))/(float)(2*k);
        if(isAnInteger(a))
        {
            sum=(k/2.0)*(2*a+(k-1)*i);
            if(sum==n)
            {
                answer=(answer+1)%1000000007;
                printf("temp = %d\tk = %d",temp,k);

                printf("first term = %g \tdifference = %d\n",a,i);
            }
        }
    }
            }
    printf("%d",answer);

    //printf("%d",isAnInteger(-4.001));
    return 0;
}
int isAnInteger(float f)
{
    if((int)f==f && f>0)
        return 1;
    return 0;
}
