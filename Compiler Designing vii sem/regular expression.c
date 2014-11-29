#include<stdio.h>
#include<string.h>
int isStringMatching(char*s1,char*s2,int a,int b,int c)
{
    int i,j;
    if(a<0 || b<0 || c<0)
        return 1;
    for(i=a,j=c;i<=b;i++,j++)
        if(s1[i]!=s2[j])
            return 0;

    return 1;
}
int omitSequenceOf(char ch,char*t,int indexT)
{
    while(t[indexT])
        if(t[indexT]==ch)
            indexT++;
        else
            break;
    return indexT;
}
int isValidExpression(char *r,char *t)
{
    int i,j,indexT,indexR;
    if(r[0]>'z' || r[0]<'a')
    {
        printf("Invalid regular expression\n");
        return 0;
    }
    for(i=0;t[i];i++)
        if(t[i]>'z' && t[i]<'a')
        {
            printf("The text you entered is not a valid text\n");
            return 0;
        }
    indexT=0;
    indexR=0;
    for(i=0;r[i];i++)
    {
        if(r[i]=='*' || r[i]=='+')
        {
            if(!isStringMatching(r,t,indexR,i-2,indexT))
                return 0;
            if(i-2<0)
                indexT=0;
            else
                indexT=indexT+i-2-indexR+1;
            if(r[i]=='*')
                indexT=omitSequenceOf(r[i-1],t,indexT);
            else if(r[i]=='+')
            {
                if(t[indexT]==r[i-1])
                {
                    indexT=omitSequenceOf(r[i-1],t,indexT+1);
                }
                else
                {
                    return 0;
                }
            }
            if(r[i-1]==r[i+1])
                indexT--;
            indexR=i+1;
        }
    }
    if(isStringMatching(r,t,indexR,strlen(r)-1,indexT))
    {
        indexT+=strlen(r)-indexR;
        if(!t[indexT])
            return 1;
        else
            return 0;
    }
}
int main()
{
    char r[1000];
    char t[10000];
    printf("Enter the regular expression : \n");
    scanf("%s",r);

    printf("Enter the string to match with the regular expression : \n");
    scanf("%s",t);
    if(isValidExpression(r,t))
        printf("\nVALID\n");
    else
        printf("\nINVALID\n");
    return 0;
}
