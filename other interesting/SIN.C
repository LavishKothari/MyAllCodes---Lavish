#include<stdio.h>
#include<math.h>
#include<conio.h>

float f(int);
int main()
{
	int i,j;
	float num,sum_sin=0,sum_cos=1;
	clrscr();
	printf("ENTER ARGUMENT IN RADIANS : ");
	scanf("%f",&num);

	for(i=0,j=0;i<20;i=i+2,j++)
	{
		sum_sin+=pow(-1,j)*pow(num,i+1)/f(i+1);
	}

	for(i=2,j=1;i<20;i=i+2,j++)
	{
		sum_cos+=pow(-1,j)*pow(num,i)/f(i);
	}



	printf("\n\nsin(%f) = %f\n",num,sum_sin);
	printf("ACTUAL VALUE OF sin(%f) = %f\n",num,sin(num));

	printf("\n\ncos(%f) = %f\n",num,sum_cos);
	printf("ACTUAL VALUE OF sin(%f) = %f",num,cos(num));

	getch();
	return 1;
}


float f(int i)
{
	int j;
	float fact=1;
	for(j=0;j<i;j++)
		fact*=(j+1);
	return fact;
}
