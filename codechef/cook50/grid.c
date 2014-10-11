#include<stdio.h>
int *flagc;
int *flagr;
int checkRowColumn(char**arr,int a,int b,int n)
{
    int i;
    if(flagc[b] || flagr[a])
        return 0;

    return 1;
}
int main()
{
    int i,n,t,j,answer;

    char **arr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        arr=(char**)malloc(sizeof(char*)*n);
        for(i=0;i<n;i++)
            arr[i]=(char*)malloc(sizeof(char)*(n+1));

        flagc=(int*)malloc(sizeof(int)*n);
        flagr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            flagr[i]=flagc[i]=0;
        for(i=0;i<n;i++)
            scanf("%s",arr[i]);
        answer=0;
        for(i=n-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(arr[i][j]=='#')
                {
                    flagc[j]=1;
                    flagr[i]=1;
                    //break;
                }
                if(arr[i][j]=='.' && checkRowColumn(arr,i,j,n))
                    answer++;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
