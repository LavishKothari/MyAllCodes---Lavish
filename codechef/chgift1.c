#include<stdio.h>

int main()
{
    int prev,i,next,t,answer,n,element,min;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

            for(i=0;i<n;i++)
            {
                scanf("%d",&element);
                if(i==0)
                    min=element;
                else
                {
                    if(element*prev<min)
                        min=element*prev;
                    if(prev-element<min)
                        min=prev-element;
                    if(prev+element<min)
                        min=prev+element;
                }
                prev=min;
            }

        printf("%d\n",min);
    }
}
