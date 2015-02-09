// first trial

#include<stdio.h>

int calculateS(int*t)
{
    int i,s[20001];
    s[0]=290797;
    t[0]=s[0]%500;
    for(i=1;i<=20000;i++)
    {
        s[i]=((((long long int)(s[i-1])*s[i-1])%50515093));
        t[i]=s[i]%500;
    }
}

int direction(int xi,int yi,int xj,int yj,int xk,int yk)
{
    int ax,ay,bx,by;
    ax=xk-xi;
    ay=yk-yi;
    bx=xj-xi;
    by=yj-yi;

    return (ax*by-bx*ay);
}

int segmentsIntersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int d1,d2,d3,d4;
    d1=direction(x3,y3,x4,y4,x1,y1);
    d2=direction(x3,y3,x4,y4,x2,y2);
    d3=direction(x1,y1,x2,y2,x3,y3);
    d4=direction(x1,y1,x2,y2,x4,y4);
    if(((d1>0&&d2<0) || (d1<0&&d2>0)) && ((d3>0&&d4<0) || (d3<0&&d4>0)))
        return 1;
    return 0;
}

int main()
{
    int t[20001],i,j,answer=0;
    calculateS(t);
    for(i=0;i<5000;i++)
        for(j=i+1;j<5000;j++)
            if(segmentsIntersect(t[i*4+1],t[i*4+2],t[i*4+3],t[i*4+4],t[j*4+1],t[j*4+2],t[j*4+3],t[j*4+4]))
                answer++;
    printf("answer = %d\n",answer);
    return 0;
}
