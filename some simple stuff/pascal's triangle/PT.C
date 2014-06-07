#include<stdio.h>
#include<conio.h>

double nCr(int,int);
double factorial(int);

int main()
{
	int r,i,j;
	clrscr();
	printf("ENTER THE NUMBER OF ROWS : ");
	scanf("%d",&r);

	for(i=0;i<r;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(i==j)
			{
				printf("1\t");
			}
			else
			{
				printf("%0.0lf\t",nCr(i,j));
			}
		}
		printf("\n");
	}

	getch();
	return 1;
}


double nCr(int i,int j)
{
	return factorial(i)/(factorial(j)*factorial(i-j));
}

double factorial(int n)
{
	double fact=1;
	int i=1;
	for(i=1;i<=n;i++)
		fact*=i;

	return fact;
}


