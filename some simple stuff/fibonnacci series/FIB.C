#include<stdio.h>
#include<conio.h>

int main()
{
	int num,i;
	double a=0,b=1,c;
	clrscr();
	printf("ENTER THE TERM NUMBER : ");
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		c=a+b;
		if(i==num-3)
		{
			printf("%0.0lf",c);
			break;
		}
		a=b;
		b=c;
	}
	getch();
	return 1;
}



