#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int gcd3(int a,int b,int c)
{
    if(gcd(a,c)==1)
        return 1;
    if(gcd(b,c)==1)
        return 1;
    return gcd(gcd(a,b),c);
}
int main()
{
    int n,*arr,i,j,k;
    int answer;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    answer=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            answer+=(n-1-i)*(n-1-i-1)/2;

            continue;
        }
        for(j=i+1;j<n;j++)
        {
            if(gcd(arr[i],arr[j])==1)
            {
                answer+=n-j-1;
            }
            else
            {
                for(k=j+1;k<n;k++)
                {
                    if(gcd3(arr[i],arr[j],arr[k])==1)
                        answer++;
                }
            }
        }
    }
    printf("%d\n",answer);
    return 0;
}
