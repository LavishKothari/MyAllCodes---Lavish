#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
int main()
{
    int n,m,i,*arr,*flag,counter,*answer,l;
    scanf("%d%d",&n,&m);
    arr=(int*)malloc(sizeof(int)*n);
    answer=(int*)malloc(sizeof(int)*n);
    flag=(int*)malloc(sizeof(int)*(MAX+1));
    for(i=0;i<=MAX;i++)
        flag[i]=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        flag[arr[i]]++;
    }
    counter=0;
    for(i=0;i<=MAX;i++)
        if(flag[i])
            counter++;
    answer[0]=counter;
    //printf("\ncounter = %d\n",counter);
    /*
    ///////////////
    for(i=0;i<=20;i++)
        printf("%d ",flag[i]);
    ///////////////
    */
    for(i=1;i<n;i++)
    {
        if(flag[arr[i-1]]==1)
            answer[i]=answer[i-1]-1;
        else
            answer[i]=answer[i-1];   
        flag[arr[i-1]]--;
    }
    
    for(i=0;i<m;i++)
    {
        scanf("%d",&l);
        printf("%d\n",answer[l-1]);
    }
    return 0;    
}
