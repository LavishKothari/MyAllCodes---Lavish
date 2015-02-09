#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num=5,i;
    char tmp;
    FILE *fp;
    int **arr,**min;
    arr=(int**)malloc(sizeof(int*)*num);
    min=(int**)malloc(sizeof(int*)*num);
    for(i=0;i<num;i++)
        arr[i]=(int*)malloc(sizeof(int)*num);
    for(i=0;i<num;i++)
        min[i]=(int*)malloc(sizeof(int)*num);

    fp=fopen("matrix.txt","r");
    if(fp)
    {
        for(i=0;i<num;i++)
        {
            for(j=0;j<num-1;j++)
                fscanf(fp,"%d %c",&arr[i][j],&tmp);
            fscanf(fp,"%d",&arr[i][j]);
        }

        min[0][0]=arr[0][0];
    }

    else
        printf("\nThe file could not be opened!!!...");
    return 0;
}
