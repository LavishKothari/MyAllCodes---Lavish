#include<stdio.h>

int main()
{
    int n,m,number,counter,max,globalmax,j,k,i;
    char **arr;
    scanf("%d%d",&n,&m);
    arr=(char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++)
        arr[i]=(char*)malloc(sizeof(char)*(m+1));

    for(i=0;i<n;i++)
        scanf("%s",arr[i]);

    globalmax=0;
    number=0;

    for(i=0;i<n;i++)
    {
        max=0;
        for(j=i+1;j<n;j++)
        {
            counter=0;
            for(k=0;k<m;k++)
                if(arr[i][k]=='1' || arr[j][k]=='1')
                    counter++;
            if(counter>max)
                max=counter;
        }
        if(max!=0)
        {
            if(max==globalmax)
                number++;
            if(max>globalmax)
            {
                globalmax=max;
                number=1;
            }
        }
    }
    printf("%d\n%d",globalmax,number);
    return 0;
}
