#include<stdio.h>
#define MOD 1000000007
int answer=0;
void findAnswer(int*arr,int start,int end)
{
    if(end-start==1 && arr[start]==arr[end])
        answer=(answer+1)%MOD;
    else if(end-start==1)
        return ;
    for(i=start;i<=end;i++)
    {
        for(j=start+1;j<=end;j++)
        {

            findAnswer(arr,i,j);
        }
    }
}
int main()
{
    int t,n,*arr;
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        printf("%d",findAnswer(arr,0,n-1));
    }
    return 0;
}
