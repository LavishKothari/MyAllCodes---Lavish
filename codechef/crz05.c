#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,*arr,answer=0;
    scanf("%d",&n);
    element=(int*)malloc(sizeof(int));
    arr=(int**)malloc(sizeof(int*)*n);

    for(i=0;i<n;i++)
    {
        arr[i]=(int*calloc(n,sizeof(int)));
        scanf("%d",&element[i]);
    }
    for(i=1;i<n;i++)
        arr[i][i]=1;
    for(i=0;i<n;i++)
    {
        i_copy=i;
        a=arr[i];
        while(1)
        {

            b=arr[arr[a]-1];
            if(b==a)
                break;



            arr[a-1]=a;
            a=b;
            i_copy=a-1;
        }
    }
    printf("Number of inversions are %d",answer);
    return 0;
}
