#include<stdio.h>
#include<math.h>
int main()
{
    int n,temp,i,answer;
    double maxpow,maxpowc,a=1.0;
    scanf("%d",&n);
    maxpow=maxpowc=pow(2,n);
    for(i=n-1;i>=0;i--)
    {
        scanf("%d",&temp);
        maxpowc/=2.0;
        a=a+temp*maxpowc;
    }
    answer=(int)(a/maxpow);
    if(a/maxpow-answer > 0 || a/maxpow-answer < 0)
        answer++;
    printf("%d\n",answer);
    return 0;
}
