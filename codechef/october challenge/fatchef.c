#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,m,n,t,min,d,prev;
    long long product;
    char *ch,a;
    scanf("%d",&t);
    while(t--)
    {
        product=1;
        min=2147483647;
        scanf("%d%d",&n,&m);
        ch=(char*)malloc(sizeof(char)*n);
        for(i=0;i<n;i++)
            ch[i]='*';
        for(i=0;i<m;i++)
        {
            scanf(" %c %d",&a,&d);
            d--;
            ch[d]=a;
            if(min>d)
                min=d;
        }
        prev=min;
        for(i=min+1;i<n;i++)
        {
            if(ch[i]!='*')
            {
                if(ch[i]==ch[prev])
                ;
                else
                {
                    product=(product*(long long)(i-prev))%1000000009;
                }
                prev=i;
            }

        }
        printf("%lld\n",product);
    }
    return 0;
}
