#include<stdio.h>
#include<conio.h>

int main()
{
	int *ptr,i=0;
	long j;
	clrscr();
	ptr=0;
	ptr++;
	printf("Size of integer on your compiler is %d\n",ptr);
	printf("Size of integer using sizeof operator = %d\n",sizeof(int));
	while(i>=0)
		j=i++;

	printf("Range = %d to %ld",i,j);
	getch();
	return 1;
}
