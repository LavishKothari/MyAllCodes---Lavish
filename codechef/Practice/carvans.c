#include<stdio.h>

int main()
{
    int t,current,prev,min,n,i,answer;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&prev);
        min=prev;
        answer=1;
        for(i=1;i<n;i++)
        {
            scanf("%d",&current);
            if(current<min)
            {
                min=current;
                answer++;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
