#include<stdio.h>


void rotateby90(int **narr,int**arr,int n)
{
    int i,j,k,l;

    for(i=0,j=n-1;i<n;i++,j--)
        for(k=0,l=0 ;k<n;k++,l++)
            narr[k][j]=arr[i][l];
}

void rotate(int**arr,int n,int angle)
{
    int**narr,**oarr,i,j;
    narr=(int**)malloc(sizeof(int*)*n);
    oarr=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
    {
        narr[i]=(int*)malloc(sizeof(int)*n);
        oarr[i]=(int*)malloc(sizeof(int)*n);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            oarr[i][j]=arr[i][j];
    if(angle==0)
        print(arr,n);
    else if(angle==90)
    {
        rotateby90(narr,arr,n);
        print(narr,n);
    }
    else if(angle==180)
    {
        rotateby90(narr,arr,n);
        rotateby90(arr,narr,n);
        print(arr,n);
    }
    else if(angle==270)
    {
        rotateby90(narr,arr,n);
        rotateby90(arr,narr,n);
        rotateby90(narr,arr,n);
        print(narr,n);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr[i][j]=oarr[i][j];
}

void print(int**arr,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int m,n,**arr,**narr,angle,i,j;

    scanf("%d%d",&n,&m);
    arr=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        arr[i]=(int*)malloc(sizeof(int)*n);
    narr=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        narr[i]=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);

    for(i=0;i<m;i++)
    {
        scanf("%d",&angle);
        rotate(arr,n,angle%360);
    }

    return 0;
}
