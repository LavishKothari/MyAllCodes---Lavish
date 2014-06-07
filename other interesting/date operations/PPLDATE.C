/*
	3 / 8 /2013   14 : 56 : 49
	by Lavish Kothari
*/

/*
	PROGRAM FOR APPLYING DATE OPEREATION
*/

#include<stdio.h>
#include<conio.h>

long formDate(int,int,int);
long incrementByDays(long,long);
long decrementByDays(long,long);
void printDate(long);
long formDate(int,int,int);
void checkForWeekDay(long);
int isLeapYear(int);
long countDaysInYear(int);
int validation(long);
long countNumberOfDays(long,long);
int daysIn(int,int);

int main()
{
	long date,date1,date2,days,newdate;
	int choice,year,month;
	while(1)
	{
		printf("\nENTER ANY DATE IN YYYYMMDD FORMAT WITHOUT SPACES\n");
		printf("\nYOU HAVE THE FOLLOWING CHOICES : ");
		printf("\n1.CHECK WHETHER A DATE IS VALID OR NOT");
		printf("\n2.CHECK FOR LEAP YEAR");
		printf("\n3.COUNT THE NUMBER OF DAYS BETWEEN TWO DATES");
		printf("\n4.CHECK THE NUMBER OF DAYS IN A MONTH OF A PARTICULAR YEAR");
		printf("\n5.INCREMENT THE DATE BY FIXED NUMBER OF DAYS");
		printf("\n6.DECREMENT THE DATE BY FIXED NUMBER OF DAYS");
		printf("\n7.CHECK THE DAY OF WEEK ON A PARTICULAR DATE");
		printf("\n8.EXIT");

		printf("\n\nENTER YOUR CHOICE : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("ENTER A DATE : ");
				scanf("%ld",&date);
				if(validation(date))
					printf("\nYOU HAVE ENTERED A VALID DATE");
				else
					printf("\nYOU HAVE NOT ENTERED A VALID DATE");
				break;

			case 2:
				printf("\nENTER THE YEAR : ");
				scanf("%d",&year);
				if(isLeapYear(year))
					printf("\nTHE YEAR YOU ENTERED IS A LEAP YEAR");
				else
					printf("\nTHE YEAR YOU ENTERED IS NOT A LEAP YEAR");
				break;

			case 3:
				printf("\nENTER FIRST DATE : ");
				scanf("%ld",&date1);
				printf("\nENTER SECOND DATE : ");
				scanf("%ld",&date2);
				if(validation(date1) && validation(date2))
				{
					days=countNumberOfDays(date1,date2);
					printf("\nNUMBER OF DAYS = %ld",days);
				}
				else
					printf("\nYOU HAVE ENTERED AN INVALID DATE");
				break;

			case 4:
				printf("\nENTER THE YEAR");
				scanf("%d",&year);
				printf("\nENTER THE MONTH");
				scanf("%d",&month);
				printf("\nDAYS IN %d OF %d ARE %d",month,year,daysIn(year,month));
				break;

			case 5:
				printf("\nENTER THE DATE : ");
				scanf("%ld",&date);
				if(validation(date))
				{
					printf("\nENTER THE NUMBER OF DAYS : ");
					scanf("%ld",&days);
					newdate=incrementByDays(days,date);
					printDate(newdate);
				}
				else
					printf("\nYOU HAVE NOT ENTERED A VALID DATE");

				break;

			case 6:
				printf("\nENTER THE DATE : ");
				scanf("%ld",&date);
				if(validation(date))
				{
					printf("\nENTER THE NUMBER OF DAYS : ");
					scanf("%ld",&days);
					newdate=decrementByDays(days,date);
					printDate(newdate);
				}
				else
					printf("\nYOU HAVE NOT ENTERED A VALID DATE");

				break;

			case 7:
				printf("ENTER A DATE : ");
				scanf("%ld",&date);
				if(validation(date))
				{
					checkForWeekDay(date);
				}
				else
					printf("\nYOU HAVE NOT ENTERED A VALID DATE");

				break;

			case 8:
				exit(0);

			default:
				printf("\nYOU HAVE ENTERED A WRONG CHOICE");
		}
		getch();
		clrscr();
	}
	getch();
	return 0;
}


long formDate(int y,int j,int k)
{
	long date;
	date=(long)y*10000+j*100+k;
	return date;
}

void checkForWeekDay(long date)
{
	long days;
	days=countNumberOfDays(101,date);
	switch(days%7)
	{
		case 0:
			printf("\nFRIDAY");
			break;
		case 1:
			printf("\nSATURDAY");
			break;
		case 2:
			printf("\nSUNDAY");
			break;
		case 3:
			printf("\nMONDAY");
			break;
		case 4:
			printf("\nTUESDAY");
			break;
		case 5:
			printf("\nWEDNESDAY");
			break;
		case 6:
			printf("\nTHRUSDAY");
			break;
	}
}
void printDate(long date)
{
	int d,m,y;
	if(validation(date))
	{
		d=date%100;
		m=(date%10000)/100;
		y=date/10000;
		printf("\n%d / %d / %d",d,m,y);
	}
	else
		printf("\nTHE DATE THAT YOU WISH TO PRINT IS AN INVALID DATE");
}


long incrementByDays(long days,long date)
{
	int i,j,k,d,m,y;
	long newdate;

	d=date%100;
	m=(date%10000)/100;
	y=date/10000;

	j=m;
	k=d;
	for(i=y;;i++)
	{
		for(;j<=12;j++)
		{
			for(;k<=31;k++)
			{
				newdate=formDate(i,j,k);

				if(validation(newdate))
				{
					if(countNumberOfDays(date,newdate)==days)
						return newdate;
				}
			}
			k=1;
		}
		j=1;
	}
	return 0;
}


long decrementByDays(long days,long date)
{
	int i,j,k,d,m,y;
	long newdate;

	d=date%100;
	m=(date%10000)/100;
	y=date/10000;

	j=m;
	k=d;
	for(i=y;;i--)
	{
		for(;j>=1;j--)
		{
			for(;k>=1;k--)
			{
				newdate=formDate(i,j,k);
				if(validation(newdate))
				{
					if(countNumberOfDays(date,newdate)==days)
						return newdate;
				}
			}
			k=31;
		}
		j=12;
	}
	return 0;
}


int isLeapYear(int year)
{
	if(countDaysInYear(year)==366)
		return 1;
	return 0;
}


long countNumberOfDays(long date1,long date2)
{
	long days=0,tmp;
	int y1,y2,m1,m2,d1,d2,i;

	if(date2<date1)
	{
		tmp=date2;
		date2=date1;
		date1=tmp;
	}

	/* now date2 contains a bigger number than date1 */

	d1=date1%100;
	m1=(date1%10000)/100;
	y1=date1/10000;

	d2=date2%100;
	m2=(date2%10000)/100;
	y2=date2/10000;

	for(i=y1+1;i<y2;i++)
	{
		days+=countDaysInYear(i);
	}

	if(y1!=y2)
	{
		for(i=m1+1;i<=12;i++)
		{
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
				days+=31;
			else
			{
				if(i==2 && countDaysInYear(y1)==366)
					days+=29;
				else if(i==2 && countDaysInYear(y1)==355)
					days+=28;
				else
					days+=30;
			}
		}

		for(i=d1+1;i<=daysIn(y1,m1);i++)
			days+=1;

		for(i=1;i<m2;i++)
		{
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
				days+=31;
			else
			{
				if(i==2 && countDaysInYear(y1)==366)
					days+=29;
				else if(i==2 && countDaysInYear(y1)==355)
					days+=28;
				else
					days+=30;
			}
		}

		for(i=1;i<=d2;i++)
			days+=1;
	}
	else
	{
		if(m1!=m2)
		{
			for(i=m1+1;i<m2;i++)
			{
				days+=daysIn(y1,i);
			}

			for(i=d1+1;i<=daysIn(y1,m1);i++)
				days++;
			for(i=1;i<=d2;i++)
				days++;

		}
		else
		{
			for(i=d1;i<d2;i++)
				days++;
		}
	}

	return days;
}


int daysIn(int year,int month)
{
	if(month>12||month<0||year<0)
	{
		printf("\nYOU HAVE ENTERED A WRONG YEAR");
		return 0;
	}
	if(isLeapYear(year))
	{
		if(month==2)
			return 29;
	}
	if(month==2)
		return 28;
	else if(month==2||month==4||month==6||month==9||month==11)
		return 30;
	else
		return 31;
}


int countDigits(long date)
{
	int counter=0;
	while(date)
	{
		counter++;
		date/=10;
	}
	return counter;
}


int validation(long date)
{
	int y,m,d;
	if(date<=0||date>99999999)
		return 0;

	if(countDigits(date)<3&&countDigits(date)>8)
		return 0;

	d=date%100;
	m=(date%10000)/100;
	y=date/10000;

	if(m>12||y>9999||m==0)
		return 0;
	if(d>31)
		return 0;

	if(m==2||m==4||m==6||m==9||m==11)
		if(d>30)
			return 0;


	if(countDaysInYear(y)==366 && m==2 && d>29)
		return 0;


	if(countDaysInYear(y)==365 && m==2 && d>28)
		return 0;

	return 1;
}


long countDaysInYear(int year)
{
	if(year%4!=0)
	{
		return 365;
	}
	else
	{
		if(year%100==0 && year%400==0)
			return 366;
		if(year%100==0 && year%400!=0)
			return 365;
	}
	return 366;
}