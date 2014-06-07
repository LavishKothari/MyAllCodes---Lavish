#include<stdio.h>
int getNumber(char*str,int n)
{
    return (int)(str[n]-48);
}
int main()
{
    int n,m,i,j,x;
    long long int answer;
    char str[100001];
    scanf("%d%d",&n,&m);
    scanf("%s",str);

    for(i=0;i<m;i++)
    {
        scanf("%d",&x);
        x--;
        answer=0;
        for(j=0;j<x;j++)
        {
            answer+=abs(getNumber(str,x)-getNumber(str,j));
        }
        printf("%d\n",answer);
    }
    return 0;
}
