#include<stdio.h>
int findMinSubStringIndex(char*,int,int);
int isPalindrome(char*,int,int);
int main()
{
    char carr[5001],newcarr[5001];
    int i,t,answer,n,max,first,last,temp,counter;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",carr);
        answer=0;
        while(n)
        {
            max=-1;

            for(i=0;i<n;i++)
            {
                temp=findMinSubStringIndex(carr,i,n)-i;
                if(max<(temp))
                {
                    first=i;
                    last=temp+i-1;
                    max=temp;
                }
            }

            counter=0;
            for(i=0;i<n;i++)
            {
                if(i<first || i>last)
                    newcarr[counter++]=carr[i];
            }
            n=n-(last-first+1);
            //carr=newcarr;
            for(i=0;i<n;i++)
            {
                carr[i]=newcarr[i];
            }
            answer++;
        }
        printf("%d",answer);
    }
    return 0;
}

int findMinSubStringIndex(char*carr,int i,int n)
{
    int j;
    for(j=n-1;j>=i;j--)
        if(isPalindrome(carr,i,j))
            return (j+1);
}

int isPalindrome(char*carr,int i,int j)
{
    int counter1,counter2;
    for(counter1=i,counter2=j;counter1<=(j+i)/2;counter1++,counter2--)
        if(carr[counter1]!=carr[counter2])
            return 0;
    return 1;
}
