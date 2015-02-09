#include<stdio.h>
#include<string.h>

int findAnswer(char*arr)
{
    int len=0;
    int m[11],cn,i;
    if(arr[0]==0 && arr[1]=='\0')
        return 0;

    if(arr[1]=='\0')
        return 1;
    m[0]=1;
    if(((arr[0]-'0')*10+(arr[1]-'0')<=26 &&(arr[0]-'0')*10+(arr[1]-'0')>0) && (arr[1]-'0')!=0)
        m[1]=2;
    else if(((arr[0]-'0')*10+(arr[1]-'0')<=26 &&(arr[0]-'0')*10+(arr[1]-'0')>0) && (arr[1]-'0')==0)
        m[1]=1;
    else
    {
        if((arr[1]-'0')==0)
        {
            m[1]=0;
            m[0]=0;
        }
        else
        {
            m[1]=1;
            m[0]=1;
        }
    }
    len=2;
    for(i=2;i<arr[i];i++)
    {
        len++;
        if((arr[i]-'0')!=0)
            m[i]=m[i-1];
        else
            m[i]=0;

        if((arr[i-1]-'0')*10+(arr[i]-'0')<=26 && (arr[i-1]-'0')*10+(arr[i]-'0')>0)
            m[i]+=m[i-2];
    }
    return m[len-1];
}

int main()
{
    int t,n;
    char arr[11];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",arr);
        printf("%d\n",findAnswer(arr));
    }
    return 0;
}
