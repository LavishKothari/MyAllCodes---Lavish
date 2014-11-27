#include<stdio.h>
#include<math.h>
int main()
{
    int q,x,y,xlevel,ylevel,flag=0,answer;
    char str[3];
    scanf("%d",&q);

    while(q--)
    {
        answer=0;
        scanf(" %s%d%d",str,&x,&y);
        xlevel=(int)log2(x)+1;
        ylevel=(int)log2(y)+1;
        if(str[1]=='i')
        {
            if(flag==0)
                flag=1;
            else flag=0;
        }
        else if(str[1]=='r')
        {
            if(xlevel>ylevel)
            {
                while(xlevel!=ylevel)
                {
                    if(xlevel%2==0 && flag==0)
                        answer++;
                    if(xlevel%2!=0 && flag==1)
                        answer++;
                    x/=2;
                    xlevel--;
                }
            }
            else
            {
                while(xlevel!=ylevel)
                {
                    if(ylevel%2==0 && flag==0)
                        answer++;
                    if(ylevel%2!=0 && flag==1)
                        answer++;
                    y/=2;
                    ylevel--;
                }
            }
            while(x!=y)
            {
                if(xlevel%2==0 && flag==0)
                    answer+=2;
                if(xlevel%2!=0 && flag==1)
                    answer+=2;
                x/=2;y/=2;
                xlevel--;ylevel--;
            }
            if(xlevel%2==0 && flag==0)
                answer++;
            if(xlevel%2!=0 && flag==1)
                answer++;
            printf("%d\n",answer);
        }
        else if(str[1]=='b')
        {
            if(xlevel>ylevel)
            {
                while(xlevel!=ylevel)
                {
                    if(xlevel%2!=0 && flag==0)
                        answer++;
                    if(xlevel%2==0 && flag==1)
                        answer++;
                    x/=2;
                    xlevel--;
                }
            }
            else
            {
                while(xlevel!=ylevel)
                {
                    if(ylevel%2!=0 && flag==0)
                        answer++;
                    if(ylevel%2==0 && flag==1)
                        answer++;
                    y/=2;
                    ylevel--;
                }
            }
            while(x!=y)
            {
                if(xlevel%2!=0 && flag==0)
                    answer+=2;
                if(xlevel%2==0 && flag==1)
                    answer+=2;
                x/=2;y/=2;
                xlevel--;ylevel--;
            }
            if(xlevel%2!=0 && flag==0)
                answer++;
            if(xlevel%2==0 && flag==1)
                answer++;
            printf("%d\n",answer);
        }
    }
    return 0;
}
