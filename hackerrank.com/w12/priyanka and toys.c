#include<stdio.h>

int main()
{
    int n,flag[10010]={0};
    int temp,answer,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        flag[temp]++;
    }
    i=0;
    answer=0;
    while(i<=10000)
    {
        if(flag[i]==0)
            i++;
        else
        {
            answer++;
            i+=5;
        }
    }
    printf("%d\n",answer);
    return 0;
}
