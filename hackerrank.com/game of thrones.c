
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

findPalind(char *str)
{
    int flag = 0,i;
    int arr[26],odd=0;
    for(i=0;i<26;i++)
        arr[i]=0;
    for(i=0;str[i];i++)
    {
        arr[str[i]-97]++;
    }
    for(i=0;i<26;i++)
        if(arr[i]%2!=0)
            odd++;
    if (odd<=1)
        printf("YES\n");
    else
        printf("NO\n");

    return;
}
int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}
