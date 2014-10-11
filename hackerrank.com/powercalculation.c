#include<stdio.h>

int main()
{
    int t,answer,globalAnswer,i,j;
    long long int n,k;
    scanf("%d",&t);
    while(t--)
    {
        globalAnswer=0;
        scanf("%lld%lld",&k,&n);
        for(i=1;i<=k;i++)
        {
            answer=1;
            for(j=0;j<n;j++)
                answer=(answer*i)%100;
            globalAnswer=(globalAnswer+answer)%100;
        }
        if(globalAnswer/10==0)
            printf("0%d\n",globalAnswer);
        else
            printf("%d\n",globalAnswer);
    }
    return 0;
}
