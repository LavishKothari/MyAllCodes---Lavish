#include<stdio.h>

int main()
{
    char str[100001],a[100001];
    int t,min,deletions,flag,k,counter,initial,len;
    char i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s",str);
        flag=0;
        for(k=1;str[k];k++)
            if(str[k]!=str[k-1])
                flag=1;
        len=k;
        a[0]=str[0];
        counter=1;
        deletions=0;
        for(k=1;str[k];k++)
        {
            while(str[k]==str[k-1])
            {
                deletions++;
                k++;
            }
            a[counter++]=str[k];
        }
        initial=deletions;
        printf("%d\n",initial);

    }
    return 0;
}
