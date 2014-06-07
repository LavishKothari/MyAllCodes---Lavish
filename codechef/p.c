#include<stdio.h>

int main()
{
    FILE*fptr;
    char arr[50];
    if(fptr=fopen("PRIMENO.TXT","r"))
    {
        while(1)
        {
            fscanf(fptr,"%s",arr);
            num=atoi(arr);
            printf("%d\n",num);
        }
    }
}
