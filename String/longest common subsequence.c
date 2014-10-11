#include<stdio.h>

char*findSubString(char str1[],char str2[])
{
    char subString[1000];
    for(i=0;str1[i];i++)
    {
        for(j=0;str2[j];j++)
        {

        }
    }
}

int main()
{
    char str1[1000],str2[1000],*subString;
    printf("Enter first String : \n");
    scanf("%s",str1);
    printf("\nEnter second String : \n");
    scanf("%s",str2);

    subString=findSubString(str1,str2);
    return 0;
}
