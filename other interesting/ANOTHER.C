#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	char *arr,*ptr;
	int i,j,flag;
	clrscr();

	ptr="lavi kothari";

	for(i=0;i<100;i++)
		arr[i]='\0';
	mahaveer:
	printf("ENTER THE PASSWORD TO LOGIN:\n");

	for(i=0;i<100;i++)
	{
	   arr[i]=getch();
	   printf("*");
	   if(arr[i]==13)
			break;
	}
	printf("\b \b");

	flag=0;
	for(j=0;j<i;j++)
		if(ptr[j]!=((char)arr[j]))
			flag++;


	if((flag==0)&&(strlen(ptr)==i))
		printf("\nLOGIN SUCCESSFUL!!!");
	else
	{
		printf("\nLOGIN FALIURE!!! Login again to continue...");
		getch();
		clrscr();
		goto mahaveer;
	}

	getch();
	return 1;
}
