#include<stdio.h>
int main()
{
    int mat[80][80],minimum[80][80],i,j,n;
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
        minimum[0][0]=mat[0][0];
        for(j=1;j<n;j++)
            minimum[0][j]=minimum[0][j-1]+mat[0][j];
        for(i=1;i<n;i++)
            minimum[i][0]=minimum[i-1][0]+mat[i][0];
        for(i=1;i<n;i++)
            for(j=1;j<n;j++)
                minimum[i][j]=(minimum[i][j-1]>minimum[i-1][j]?minimum[i-1][j]:minimum[i][j-1])+mat[i][j];
        printf("answer = %d\n",minimum[n-1][n-1]);
    }
    else
        printf("there is some error in opening the file\n");
    return 0;
}
