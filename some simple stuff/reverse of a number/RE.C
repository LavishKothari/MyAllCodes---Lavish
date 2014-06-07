#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char num[50];
	int i;
	clrscr();
	printf("ENTER THE NUMBER : ");
	gets(num);

	printf("\nREVERSE OF THE NUMBER IS : \n");

	for(i=strlen(num)-1;i>=0;i--)
		printf("%c",num[i]);

	getch();
	return 1;
}

