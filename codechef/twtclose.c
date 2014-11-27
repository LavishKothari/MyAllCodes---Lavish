#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n,j,k,i,num,answer=0,*arr;
    char str[100];
    scanf("%d%d",&n,&k);
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        arr[i]=0;
    for(i=0;i<k;i++)
    {
        scanf(" %s",str);
        if(str[2]!='O')
        {
            scanf("%d",&num);
            if(arr[num-1]==0)
            {
                answer++;
                arr[num-1]=1;
            }
            else
            {
                answer--;
                arr[num-1]=0;
            }
        }
        else
        {
            for(j=0;j<n;j++)
                arr[j]=0;
            answer=0;
        }

        printf("%d\n",answer);
    }
    return 0;
}
