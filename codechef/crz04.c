#include<stdio.h>

int main()
{
    int MM,HH,MMangle,t;
    float answer,HHangle;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&HH,&MM);
        //printf("%d %d\n",HH,MM);
        if(HH>23 || MM>59)
        {
            printf("Invalid Time\n");
            continue;
        }
        HH=HH%12;
        MMangle=MM*6;
        HHangle=HH*30+0.5*MM;

        answer=MMangle-HHangle;
        if(answer<0)
            answer*=(-1);

        if(answer>180)
            answer=360-answer;
        printf("%.1f\n",answer);

    }
    return 0;
}
