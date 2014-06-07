#include<stdio.h>
#include<conio.h>

int main()
{
	int n;
	unsigned int cal_add,base_add;
	int arr[10];
	clrscr();

	printf("ENTER AN INTEGER BETWEEN 0 - 9 :\n");
	scanf("%d",&n);

	base_add=(unsigned int)arr;
	cal_add=base_add+n*sizeof(int);

	printf("Actual Address = %u\n",&arr[n]);
	printf("Calculated Address = %u",cal_add);
	getch();
	return 0;
}


