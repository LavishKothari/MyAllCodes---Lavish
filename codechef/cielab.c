#include<stdio.h>
int countDigits(long long int n)
{
    int answer=0;
    while(n>0)
    {
        answer++;
        n/=10;
    }
    return answer;
}
int *formArray(long long int n)
{
    int len,*arr,i;
    len=countDigits(n);
    arr=(int*)malloc(sizeof(int)*len);
    for(i=len-1;i>=0;i--)
    {
        arr[i]=n%10;
        n/=10;
    }
    return arr;
}
int main()
{
    int a,b,answer;
    scanf("%d%d",&a,&b);
    answer=a-b;
    if(answer%10==9)
        printf("%d",answer-1);
    else printf("%d",answer+1);
    return 0;
}
