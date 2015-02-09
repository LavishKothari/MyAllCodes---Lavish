#include<stdio.h>
#include<stdlib.h>
int* returnArrayOfInputSymbols(char*s)
{
    int *flag,i;
    flag=(int*)malloc(sizeof(int)*26);

    for(i=0;i<26;i++)
        flag[i]=0;
    for(i=0;s[i];i++)
        if(s[i]<='z' && s[i]>='a')
            flag[s[i]-'a']++;
    return flag;
}

int findNumberOfStates(char*s)
{
    int numberOfStates=1,i;
    for(i=0;s[i];i++)
        if(s[i]>='a' && s[i]<='z' && s[i+1]!='*')
            numberOfStates++;
    return numberOfStates;
}

int main()
{
    int *flag,i,counter;
    int numberOfInputSymbols=0,numberOfStates=0;
    char s[1000];
    printf("Enter a regular expression containing only star symbol and lower case alphabets : \n");
    scanf("%s",s);
    flag=returnArrayOfInputSymbols(s);
    numberOfStates=findNumberOfStates(s);

    printf("THE FINITE AUTOMATA IS : \n\n");
    printf("Input Symbols : ");
    for(i=0;i<26;i++)
        if(flag[i])
            printf("%c,",i+'a');

    printf("\nThe set of states is : ");
    for(i=0;i<numberOfStates;i++)
        printf("q%d,",i);
    printf("\nThe initial states is : q0");
    printf("\nThe Transition Function is : \n");
    counter=0;
    for(i=0;s[i];i++)
    {
        if(s[i]=='*')
            continue;
        printf("(q%d,%c) -> ",counter,s[i]);
        if(s[i+1]!='*')
            counter++;
        printf("q%d\n",counter);
    }
    printf("The final state is : q%d\n",numberOfStates-1);
    return 0;
}
