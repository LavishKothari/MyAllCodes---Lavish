#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int findMax(int*arr,int sizearr,int n)
{
    int val,max=0,maxindex,i;
    for(i=0;i<sizearr;i++)
    {
        val=abs(arr[i]-n);
        if(val>max)
        {
            max=val;
            maxindex=i;
        }
    }
    return abs(arr[maxindex]-n);
}

int main()
{
    int t,n,m,*arr,*a,i,div,max,min;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        arr=(int*)malloc(sizeof(int)*m);
        a=(int*)malloc(sizeof(int)*n);

        max=0;
        min=2147483647;

        for(i=0;i<m;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]>max)
                max=arr[i];
            if(arr[i]<min)
                min=arr[i];
        }
        div=(min+max)/2;
        for(i=0;i<n;i++)
        {
            if(i<=div)
                a[i]=max-i;
            if(i>div)
                a[i]=i-min;
        }


        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
