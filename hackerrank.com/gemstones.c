#include<stdio.h>

int main()
{

    int n,i,j,answer,counter;
    int **flag;
    char**str;
    scanf("%d",&n);

    str=(char**)malloc(sizeof(char*)*n);
    flag=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
    {
        str[i]=(char*)malloc(sizeof(char)*101);
        flag[i]=(int*)malloc(sizeof(int)*26);
    }
    for(i=0;i<n;i++)
        for(j=0;j<26;j++)
            flag[i][j]=0;

    for(i=0;i<n;i++)
    {
        scanf("%s",str[i]);
        for(j=0;str[i][j];j++)
            flag[i][(int)str[i][j]-97]++;
    }

    answer=0;
    for(i=0;i<26;i++)
    {
        counter=0;
        for(j=0;j<n;j++)
            if(flag[j][i]==0)
            {
                counter=1;
                break;
            }
        if(!counter)
            answer++;
    }
    printf("%d",answer);
    return 0;
}
