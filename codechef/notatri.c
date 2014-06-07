#include<stdio.h>
#include<stdlib.h>
int comparisionFunction(const void * a,const void * b);


int main()
{
    int n,*arr,i,answer,first,last;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        qsort(arr,n,sizeof(int),comparisionFunction);

        answer=0;
        for(i=n-1;i>1;i--)
        {
            first=0;
            last=i-1;
            while(first<last)
            {
                if(arr[first]+arr[last]<arr[i])
                {
                    answer+=last-first;
                    first++;
                }
                else
                    last--;
            }
        }

        printf("%d\n",answer);
        free(arr);
    }
    return 0;
}
int comparisionFunction(const void * a,const void * b)
{
    return strcmp((char*)a,(char*)b);
}
