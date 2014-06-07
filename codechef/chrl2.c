#include<stdio.h>

int main()
{
    char str[2001];
    int i,arr[2000]={0},j,k,l,answer=0,counterc,counterh,countere,counterf;

    counterc=countere=counterh=counterf=0;

    scanf("%s",str);

    for(i=0;str[i];i++)
    {
        if(str[i]=='C')
            counterc++;
        else if(str[i]=='H')
            counterh++;
        else if(str[i]=='E')
            countere++;
        else if(str[i]=='F')
            counterf++;
    }
    i=0;
    lavish:;
    for(;str[i] && answer<counterc && answer<countere && answer<counterf && answer<counterh;i++)
        if(str[i]=='C' && arr[i]==0)
            for(j=i+1;str[j];j++)
                if(str[j]=='H' && arr[j]==0)
                    for(k=j+1;str[k];k++)
                        if(str[k]=='E' && arr[k]==0)
                            for(l=k+1;str[l];l++)
                                if(str[l]=='F' && arr[i]==0 && arr[j]==0 && arr[k]==0 && arr[l]==0)
                                {
                                    //printf("%d %d %d %d\n",i,j,k,l);
                                    answer++;
                                    arr[i]=arr[j]=arr[k]=arr[l]=1;
                                    goto lavish;
                                }


    printf("%d",answer);
    return 0;
}
