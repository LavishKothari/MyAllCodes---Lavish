#include<stdio.h>

int main()
{
	int i,len;
	char str[100000];
	scanf("%[^\n]s",str);
	for(len=0;str[len];len++);
	for(i=len;i>=0;i--)
		printf("%c",str[i]);
	return 0;
}
