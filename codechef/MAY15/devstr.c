#include<stdio.h>
char s;
void flip(char*arr,int i)
{
    if(arr[i]=='0')
        arr[i]='1';
    else
        arr[i]='0';
}
int findWhatToFlip(char*arr,int n,int k)
{
    int counter,i;
    char current;
    if(k==1)
        return n;
    current=arr[n];
    if(current=='1')
        current='0';
    else
        current='1';
    counter=0;
    for(i=n+1;arr[i] && counter<k;i++)
    {
        if(arr[i]!=current)
            break;
        counter++;
    }
    if(counter==k)
        return n-1;
    else return n;
}
int findAnswer(char*arr,int n ,int k)
{
    int a=0,b=0,i;
    // assuming starting with 0
    for(i=0;i<n;i++)
    {
        if(i%2==0 && arr[i]!='0')
            a++;
        if(i%2!=0 && arr[i]!='1')
            a++;
    }
    
    //assuming starting with 1
    for(i=0;i<n;i++)
    {
        if(i%2==0 && arr[i]!='1')
            b++;
        if(i%2!=0 && arr[i]!='0')
            b++;
    }
    if(a<b)
        s='0';
    else
        s='1';
    return a<b?a:b;
}
int main()
{
    int t,f,answer,flag,k,n,i,j;
    char arr[100001];
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        scanf("%d%d",&n,&k);
        scanf("%s",arr);
        if(k==1)
        {
            printf("%d\n",findAnswer(arr,n,k));
            if(s=='0')
                for(i=0;i<n;i++)
                {
                    if(i%2==0) printf("0");
                    else printf("1");
                }
            else
                for(i=0;i<n;i++)
                {
                    if(i%2==0) printf("1");
                    else printf("0");
                }
            printf("\n");
            continue;
        }
        for(i=0;i<n;)
        {
            flag=0;
            for(j=0;j<k;j++)
            {
                if(arr[i+j+1]!=arr[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                i=i+j+1;
            else
            {
                f=findWhatToFlip(arr,i+j,k);
                flip(arr,f);
                answer++;
                i=f;
            }
        }
        printf("%d\n",answer);
        printf("%s\n",arr);
    }
    
    return 0;
}
