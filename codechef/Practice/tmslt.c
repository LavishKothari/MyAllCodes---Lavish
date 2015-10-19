#include<stdio.h>
#include<stdlib.h>

void initializeArray(int n,int a,int b,int c,int d);

int *flag;
long long int team1,team2,answer;

int main()
{
    int a,b,c,d,n,t,i,fflagg;
    scanf("%d",&t);
    while(t--)
    {
        fflagg=0;
        flag=(int*)calloc(1000000,sizeof(int));
        team1=team2=0;
        scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
        answer=0;
        initializeArray(n,a,b,c,d);

        for(i=0;i<1000000;i++)
        {
            if(flag[i] && fflagg==0)
            {
                fflagg=1;
                answer+=i;
            }

            else if(flag[i] && fflagg==1)
            {
                fflagg=0;
                answer-=i;
            }
            flag[i]--;
            if(flag[i]>0)
                i--;

        }

        if(answer<0)
            answer=(-1*answer);

        printf("%lld\n",answer);
        free(flag);
    }
    return 0;
}

void initializeArray(int n,int a,int b,int c,int d)
{
    int i,temp;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            temp=d;
            flag[d]++;
        }
        else
        {
            flag[(int)(((long long int)a*temp*temp + b*temp + c)%1000000)]++;
            temp=(int)(((long long int)a*temp*temp + b*temp + c)%1000000);
        }
    }
}
