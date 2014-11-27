#include<stdio.h>
#include<math.h>
#include<stdlib.h>
char keyArray[3],answerArray[3];
int maxSpaces=0;
int isAValidEnglishCharacter(char temp)
{
    if(temp<32 || temp>126)
        return 0;
    return 1;
}

int isKeyPossible(char a,char b,char c,char*arr,int n)
{
    int i,flag,spaces;
    keyArray[0]=a;
    keyArray[1]=b;
    keyArray[2]=c;

    flag=0;
    spaces=0;
    for(i=0;i<n;i++)
    {
        if(((char)keyArray[i%3]^(char)arr[i])==' ')
            spaces++;
        if(!isAValidEnglishCharacter((char)keyArray[i%3]^(char)arr[i]))
            return 0;
    }
    if(maxSpaces<spaces) // as the most common english character is space (' ')
    {
        maxSpaces=spaces;
        answerArray[0]=a;
        answerArray[1]=b;
        answerArray[2]=c;
    }
    return 1;
}

void findKey(char*arr,int n)
{
    char i,j,k;
    int l,answer[3];
    /*
        the encryption key consists of three lower case characters
    */
    for(i='a';i<='z';i++)
        for(j='a';j<='z';j++)
            for(k='a';k<='z';k++)
                if(isKeyPossible(i,j,k,arr,n))
                    printf("Key found key is %c%c%c\n",i,j,k);
}
int main()
{
    char temp;
    int answer;
    int arr[5000],numberOfElements;
    char byteArray[5000];
    int i,key;
    FILE*fptr;
    fptr=fopen("cypher1.txt","r");
    if(fptr)
    {
        for(i=0;!feof(fptr);i++)
        {
            fscanf(fptr,"%d",&arr[i]);
            byteArray[i]=(char)arr[i];
            fscanf(fptr," %c",&temp);
        }
        numberOfElements=i;
        /* eliminating the duplicates from the array */
        findKey(byteArray,numberOfElements);
        /*
        for(i=0;i<numberOfElements;i++)
            printf("%c",(key^arr[i]));
        */
        answer=0;
        /*
        keyArray[0]='g';
        keyArray[1]='o';
        keyArray[2]='d';
        */
        for(i=0;i<numberOfElements;i++)
        {
            printf("%c",(byteArray[i]^answerArray[i%3]));
            answer+=(byteArray[i]^answerArray[i%3]);
        }
        printf("\nanswer = %d\n",answer);
    }
    else
        printf("There was some problem in opening the file\n");
    return 0;
}
