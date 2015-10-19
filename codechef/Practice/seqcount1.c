#include<stdio.h>

int main()
{
    int n,k,d,answer=0,i,j;
    int sum;
    scanf("%d%d%d",&n,&k,&d);

    //printf("hello lavish kothari\n");
    if(k==1)
        answer=1;
    else
    {
        for(i=1;i<=d && i<=n;i++)// loop for the first element
        {
            for(j=1;j<=d && j<=n;j++) // loop for the difference
            {
                sum=k*i + ((k*(k-1))/2)*j;

                //printf("\n");
                if(sum==n)
                {
                    answer++;
                }
            }

        }
    }


    printf("%d",answer);
    return 0;
}
