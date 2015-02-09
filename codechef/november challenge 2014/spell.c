#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void checkString(char*str)
{
    printf("%s",str);
}
int main()
{
    int len,d,i;
    char arr[100],**dict,str[100],temp;

    scanf("%d",&d);
    dict=(char**)malloc(sizeof(char*)*d);
    for(i=0;i<d;i++)
    {
        scanf("%s",arr);
        len=strlen(arr);
        dict[i]=(char*)malloc(sizeof(char)*(len+1));
        strcpy(dict[i],arr);
    }
    i=0;
    getchar();
    while((temp=getchar())!='\n')
    {
        if(temp==' ')
        {
            str[i]='\0';

            checkString(str);

            i=0;
            continue;
        }
        str[i]=temp;
        i++;
    }
    return 0;
}
