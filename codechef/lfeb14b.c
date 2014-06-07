#include<stdio.h>

int main()
{
    int max,arr[100000],t,counter,i,n;
    long long int answer;
    scanf("%d",&t);
    while(t--)
    {
        max=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(max<arr[i])
            {
                counter=0;
                answer=1;
                max=arr[i];
            }
            if(max==arr[i])
            {
                counter++;
                answer=((answer*2)%1000000007);
            }
        }

        answer--;
        printf("%lld\n",answer);
    }
}
