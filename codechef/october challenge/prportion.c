#include<stdio.h>

int max(int a,int b,int c)
{
    if(a>=b && a>=c)
        return a;
    if(b>=a && b>=c)
        return b;
    if(c>=a && c>=b)
        return c;
}

int main()
{
    int i,m,t,rlen,glen,blen,*r,*g,*b,maxr,maxg,maxb,maximum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&rlen,&glen,&blen,&m);
        r=(int*)malloc(sizeof(int)*rlen);
        g=(int*)malloc(sizeof(int)*glen);
        b=(int*)malloc(sizeof(int)*blen);
        maxr=maxg=maxb=0;
        for(i=0;i<rlen;i++)
        {
            scanf("%d",&r[i]);
            if(maxr<r[i])
                maxr=r[i];
        }
        for(i=0;i<glen;i++)
        {
            scanf("%d",&g[i]);
            if(maxg<g[i])
                maxg=g[i];
        }
        for(i=0;i<blen;i++)
        {
            scanf("%d",&b[i]);
            if(maxb<b[i])
                maxb=b[i];
        }
        //printf("maximums are : %d %d %d\n",maxr,maxg,maxb);
        for(i=0;i<m;i++)
        {
            maximum=max(maxr,maxg,maxb);
            //printf("maximum = %d\n",maximum);
            if(maximum==maxr)
                maxr/=2;
            else if(maximum==maxg)
                maxg/=2;
            else if(maximum==maxb)
                maxb/=2;

        }
        printf("%d\n",max(maxr,maxg,maxb));
    }
    return 0;
}
