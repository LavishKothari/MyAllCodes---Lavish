#include<stdio.h>

int main()
{
    int t,n,firstMin,answer,secondMin,i,*arr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        secondMin=firstMin=1000001;

        arr=(int*)malloc(sizeof(int)*n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]<firstMin)
                firstMin=arr[i];
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]>firstMin && arr[i]<secondMin)
                secondMin=arr[i];

        }
        if(secondMin==1000001)
            secondMin=firstMin;
        answer=firstMin+secondMin;
        printf("%d\n",answer);
    }
    return 0;
}
