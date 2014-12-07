#include<stdio.h>
#define MAX 100001
int main()
{
    int flag[MAX],n,i,temp;
    int t,answer;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<=MAX;i++)
            flag[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            flag[temp]++;
        }
        answer=0;
        for(i=0;i<MAX;i++)
            if(flag[i])
                answer++;
        printf("%d\n",answer);
    }
    return 0;
}
