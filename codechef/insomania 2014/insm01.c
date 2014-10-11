#include<stdio.h>
#include<string.h>

int findIsoscelesTriangles(char*str)
{
    int answer=0,i,j,k,len;
    len=strlen(str);
    for(i=0;str[i];i++)
    {
        for(j=i+1;j<len/2;j++)
            if(str[j]==str[i])
            {
                k=2*j-i;
                if(str[j]==str[k])
                    answer++;
            }
        for(j=len/2;str[j];j++)
        {
            if(str[j]==str[i])
            {
                k=(i+j+len)/2;
                if(str[j]==str[k])
                    answer++;

            }
        }
    }
    return answer;
}
int main()
{
    int t;
    char str[1000001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        printf("%d\n",findIsoscelesTriangles(str));
    }
    return 0;
}
