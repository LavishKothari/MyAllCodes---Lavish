#include<string.h>
#include<stdio.h>

int main()
{

    int t,i,j,k;
    int counter=0;
    char a[10001],b[10001];
    int bb[10000]={0};
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        counter=0;
        scanf("%s",a);
        scanf("%s",b);
        for(j=0;j<strlen(b);j++)
            bb[j]=0;
        for(j=0;j<strlen(a);j++)
        {
            for(k=0;k<strlen(b);k++)
            {
                if(a[j]==b[k]  && !bb[k])
                {
                    counter++;
                    bb[k]=1;
                    break;
                }
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}
