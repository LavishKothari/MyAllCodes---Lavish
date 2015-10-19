#include<string.h>
#include<stdio.h>

int main()
{
    int t,i,j,k,l;
    int counter,ascounter,accounter,bscounter,bccounter;
    char a[10001],b[10001];
    int *answer;
    scanf("%d",&t);
    answer=(int*)malloc(sizeof(int)*t);
    for(i=0;i<t;i++)
    {
        counter=0;
        scanf("%s",a);
        scanf("%s",b);
        for(k=(int)'0';k<=(int)'9';k++)
        {
            ascounter=accounter=bscounter=bccounter=0;
            for(l=0;l<strlen(a);l++)
            {
                if(a[l]==(char)k)
                    ascounter++;
            }
            for(l=0;l<strlen(b);l++)
            {
                if(b[l]==(char)k)
                    bscounter++;
            }
            counter+=(ascounter<bscounter?ascounter:bscounter);
       }

        for(k=(int)'A',j=(int)'a';j<=(int)'z';k++,j++)
        {
            ascounter=accounter=bscounter=bccounter=0;
            for(l=0;l<strlen(a);l++)
            {
                if(a[l]==(char)j)
                    ascounter++;
                if(a[l]==(char)k)
                    accounter++;
            }
            for(l=0;l<strlen(b);l++)
            {
                if(b[l]==(char)j)
                    bscounter++;
                if(b[l]==(char)k)
                    bccounter++;
            }
            counter+=(ascounter<bscounter?ascounter:bscounter);
            counter+=(accounter<bccounter?accounter:bccounter);
        }
        answer[i]=counter;
    }
    for(i=0;i<t;i++)
        printf("%d\n",answer[i]);
}
