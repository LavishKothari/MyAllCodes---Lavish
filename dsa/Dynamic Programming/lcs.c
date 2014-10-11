#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int**c;
char**b;
int longestCommonSubSequence(char str1[],char str2[])
{
    int m,n,i,j;
    m=strlen(str1);
    n=strlen(str2);

    c=(int**)malloc(sizeof(int*)*(m+1));
    b=(char**)malloc(sizeof(char*)*(m+1));
    for(i=0;i<=m;i++)
    {
        c[i]=(int*)malloc(sizeof(int)*(n+1));
        b[i]=(char*)malloc(sizeof(char)*(n+1));
    }

    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(i=0;i<=n;i++)
        c[0][i]=0;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='t';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
    /*
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d%c  ",c[i][j],b[i][j]);
        }
        printf("\n");
    }
    */
    return c[m][n];
}

void printLCS(char str1[],int i,int j)
{
    /*
        printing the Longest Common SubSequence using Recursion
    */

    if(i==0 || j==0)
        return ;
    if(b[i][j]=='t')
    {
        printLCS(str1,i-1,j-1);
        printf("%c",str1[i-1]);
    }
    else if(b[i][j]=='u')
        printLCS(str1,i-1,j);
    else if(b[i][j]=='l')
        printLCS(str1,i,j-1);

}

void print1LCS(char str1[],int m,int n,int lengthOfLCS)
{
    /*
        printing the longest common subsequence without recursion.
    */
    char *LCS;
    int i,j,x,counter=0;
    LCS=(char*)malloc(sizeof(char)*lengthOfLCS);

    i=m;j=n;
    for(x=0;x<lengthOfLCS;)
    {
        printf("%c",b[i][j]);
        if(b[i][j]=='t')
        {
            LCS[x]=str1[i-1];
            i--;j--;
            x++;
        }
        else if(b[i][j]=='l')
            j--;
        else if(b[i][j]=='u')
            i--;

    }
    printf("\n");
    for(i=lengthOfLCS-1;i>=0;i--)
        printf("%c",LCS[i]);
}

int main()
{
    char str1[100],str2[100];
    int length;
    printf("Enter the first String : ");
    scanf("%s",str1);
    printf("Enter the second String : ");
    scanf("%s",str2);
    length=longestCommonSubSequence(str1,str2);
    printf("the length of LCS is %d\n",length);
    print1LCS(str1,strlen(str1),strlen(str2),length);

    return 0;
}
