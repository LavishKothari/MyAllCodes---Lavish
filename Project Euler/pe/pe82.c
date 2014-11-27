#include<stdio.h>
int mat[80][80],minimum[80][80],n;
int min2(int a,int b)
{
    return (a>b?b:a);
}
int main()
{
    int min,i,j;
    char temp;
    FILE *f;
    n=80;
    f=fopen("matrix.txt","r");
    if(f)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
                fscanf(f," %d%c",&mat[i][j],&temp);
            fscanf(f,"%d",&mat[i][j]);
        }

        for(i=0;i<n;i++)
            minimum[i][0]=mat[i][0];
        for(i=1;i<n;i++)
        {
            j=0;
            minimum[j][i]=mat[j][i]+min2(minimum[j][i-1],minimum[j+1][i-1]+mat[j+1][i]);
            for(j=1;j<n;j++)
                minimum[j][i]=mat[j][i]+min2(minimum[j][i-1],minimum[j-1][i]);

            for(j=n-2;j>=0;j--)
                minimum[j][i]=min2(minimum[j+1][i]+mat[j][i],minimum[j][i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d ",minimum[i][j]);
            printf("\n");
        }
        min=2147483647;
        for(i=0;i<n;i++)
            if(min>minimum[i][n-1])
                min=minimum[i][n-1];
        printf("answer = %d\n",min);
    }
    else
        printf("there is some error in opening the file\n");
    return 0;
}
