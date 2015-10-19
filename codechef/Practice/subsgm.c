#include<stdio.h>
int arr[100000];
int Answer();
int n,m;
int main()
{
    int i,x,y;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d\n",Answer());

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        arr[x-1]=y;
        printf("%d\n",Answer());
    }

    return 0;

}

int Answer()
{
    int i,counter=1,max=1;
    for(i=1;i<n;i++)
    {
        if((arr[i-1]+1) == arr[i])
        {
            counter++;
            if(counter>max)
                max=counter;
        }
        else
            counter=1;
    }

    return max;
}
