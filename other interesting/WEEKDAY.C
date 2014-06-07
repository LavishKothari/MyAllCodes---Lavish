//program to find day of week for a given date....

#include<stdio.h>
#include<conio.h>

void main()
{
	long int d,m,y,d1,m1,y1,d2,m2,y2,tot,lavish,i;
	clrscr();
	printf("Program to find the day of week for a given date\n\n");
	d1=1;
	m1=1;
	y1=0;
	printf("Enter the date in dd mm yyyy format: \n");
	scanf("%ld%ld%ld",&d2,&m2,&y2);

	y=y2-y1;
	m=m2-m1;
	d=d2-d1;

	tot=y*365+m*30+d;

	if(m2>2)
	{
		for(i=y1;i<=y2;i++)
		{
			if(i%4==0)
				tot++;

			if(i%100==0)
				if(i%400!=0)
					tot--;
		}
	}
	else
	{
		for(i=y1;i<y2;i++)
		{
			if(i%4==0)
				tot++;

			if(i%100==0)
				if(i%400!=0)
					tot--;
		}

	}


	if(m2>m1)
	{
		for(i=m1;i<m2;i++)
		{
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
				tot++;

			if(i==2)
				tot=tot-2;
		}

	}

	lavish=tot%7;

	printf("\n\n");

	switch(lavish)
	{
		case 0:
			printf("SATURDAY");
			break;
		case 1:
			printf("SUNDAY");
			break;
		case 2 :
			printf("MONDAY");
			break;
		case 3  :
			printf("TUESDAY");
			break;
		case 4   :
			printf("WEDNESDAY");
			break;
		case 5    :
			printf("THRUSDAY");
			break;
		case 6     :
			printf("FRIDAY");
			break;
	}
	getch();
}
