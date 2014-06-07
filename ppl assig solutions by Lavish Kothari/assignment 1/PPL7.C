#include<stdio.h>
#include<conio.h>

#define cols 10
#define rows 10

int main()
{
	int arr[rows][cols];
	int r,c;
	unsigned int cal_add,base_add;

	clrscr();
	printf("ENTER THE ROW NUMBER (between 0-9):\n");
	scanf("%d",&r);
	printf("ENTER THE COLUMN NUMBER (between 0-9): \n");
	scanf("%d",&c);

	printf("\nActual Address = %u",&arr[r][c]);

	base_add=(unsigned int)arr;
	/* row major order */
	cal_add=base_add+ (r*cols + c)*sizeof(int);

	printf("\nCalculated address = %u",cal_add);

	getch();
	return 0;
}
